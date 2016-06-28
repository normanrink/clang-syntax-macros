

## C Language Family Front-end with Support for Syntax Macros

Welcome to syntax macros in Clang.  This readme file explains what syntax macros
are and how they have been added as a language extension to C/C++.  If you are
looking for the standard Clang readme, it is located in the file README.txt in
this folder.


### Getting started

It is assumed that you are familiar with how to build Clang and LLVM.  For
further information please refer to the [LLVM](http://llvm.org/docs/GettingStarted.html)
and [Clang](http://clang.llvm.org/get_started.html) documentation.
 
Since you are reading this, you are on the `syntax-macros` branch in the
present Clang repository, obtained from [`https://github.com/normanrink/clang-syntax-macros`](https://github.com/normanrink/clang-syntax-macros).
The `syntax-macros` branch is derived from Clang 3.8.  Hence, support for syntax
macros in Clang will build against LLVM 3.8.  A version of LLVM against which
building has been tested can be obtained from [`https://github.com/normanrink/llvm-syntax-macros`](https://github.com/normanrink/llvm-syntax-macros)

Thus, to build Clang with syntax macros, do the following:

  1.  Clone a suitable version of LLVM, e.g.
      ```
      git clone git@github.com:normanrink/llvm-syntax-macros.git llvm
      ```

  2.  Check out the `syntax-macros` branch (should be checked out by default):
      ```
      cd llvm
      git checkout syntax-macros
      ```

  3.  Clone this Clang repository:
      ```
      cd tools
      git clone git@github.com:normanrink/clang-syntax-macros.git clang
      ```
 
  4.  Check out the `syntax-macros` branch (should be checked out by default):
      ```
      cd clang
      git checkout syntax-macros
      ```

  5.  Now follow the conventional build instructions for LLVM and Clang, which
      can be found on [`http://llvm.org/docs/GettingStarted.html`](http://llvm.org/docs/GettingStarted.html).

After successfully building Clang, you can run the `lit` regression tests with

    make check-clang

This will also execute the syntax macros tests in

    tools/clang/test/ast-capture

(The directory is named `ast-capture` for historic reasons: ast-capture was a
working title used instead of syntax macros.)  Alternatively, you can use `llvm-lit`
to exercise only the tests in the `ast-capture` directory:

    <BUILD-DIR>/bin/llvm-lit <SOURCE-DIR>/llvm/tools/clang/test/ast-capture

The tests in `tools/clang/test/ast-capture` are also a good place to take a first
glimpse at syntax macros.


## Syntax macros

Syntax macros are a meta-programming tool for manipulating programs.
A syntax macro binds a name to an AST (abstract syntax tree).
When a macro is invoked, the bound AST is hooked into the program's ambient AST at the locaton of the mactro invocation.

Syntax macros are typed, and their types are precisely the terminal and non-terminal symbols of the C/C++ grammar.
For example, the type of a macro may be `Stmt` (statement) or `Expr` (expression).
The macro type must agree with the type of the root node of the AST that is bound to the macro.

For the purpose of syntax macros the following tokens have been introduced:

 - `$` indicates macro invocation.
 - `$$` indicates the beginning of a macro defition.
 - `$$$` indicates instantiation of a formal macro parameter (see below).

Note that introducing these tokens means that `$` can no longer be used in C/C++ identifiers.

A simple macro definition looks like this:

   `$$[Stmt] init () int x = 1;`

This defines the macro `init` of type `Stmt`.
Macros may optionally take formal parameters, which appear inside parentheses immediately after the name of the macro.
Here there are no formal parameters, as indicated by the empty list `()`.
The body of the macro follows after the formal parameter list.
Here the body consists of a single `DeclStmt`, namely `int x = 1;`.

Macro definitions are type-checked.
In our example, the macro `init` is defined to be of type `Stmt`, and the macro body is of type `DeclStmt`.
Type-checking succedes since a `DeclStmt` is also a `Stmt`.
The macro `init` could have also been defined like this:

   `$$[DeclStmt] init () int x = 1;`

After the above macro definition has been successfully parsed, the name `init` is bound to the AST which result from parsing the macro body.
The macro `init` can then be invoked, e.g., in the following simple function:
   ```
   int simple() {
     $init
     x += 41;
     return x;
   }
   ```
The function `simple` will of course return `42`.

As a second example, let's define a macro `add` with a body of type `Expr`:

   `$$[Expr] add (Expr[int] var $ IntegerLiteral[int] num) ($$$var) + ($$$num)`

This macro takes two formal parameters: `var` and `num`.
Note that the token `$` is also used to separate formal parameters.
The formal parameters are declared with types `Expr` and `IntegerLiteral` respectively.
When formal parameters are expressions, their types must be annotated with C/C++ expression types in brackets, e.g. `[int]`.
These annotations are used for type-checking actual parameters on macro invokation.

With the `add` macro the function `simple` can be written like this:
   ```
   int simple() {
     $init
     x = ($add(x $ 41));
     return x;
   }
   ```
Note again the two meanings of the `$` token.
The `$` in `$add` indicates that the macro `add` should be invoked.
The actual parameters given to the macro invokation are `x` and the literal `41`.
The `$` in the actual parameter list separates the two actual parameters.

Macro definitions may appear everywhere where a `TopLevelDecl` or a `Stmt` is allowed.
The macro definition must then be immediately followed by a `TopLevelDecl` or a `Stmt` respectively.
Note that this can be achieved by adding a `;` after the macro definition, which is then parsed as an `EmptyDecl` or a `NullStmt` respectively.

The complete source code for the examples in this section can be found in ` test/ast-capture/simple.c`.
A more comprehensive syntax macro system has been defined and implemented by D. Weise and R. Crew of Microsoft Research  [\[1\]](http://dl.acm.org/citation.cfm?id=155105) (also accessible at [\[2\]](https://www.cs.rice.edu/~taha/teaching/05S/511/papers/weise93programmable.pdf)).


## Extending Clang

The definitions and invokations of syntax macros appear directly in C/C++ source code.
Syntax macros are therefore an extension of the C/C++ language.
Implementing a C/C++ language extension necessitates extending the parser.

In implementing syntax macros, Clang's parser is extended by deriving from the class `Parser`:
   ```
   class CaptureParser : public Parser {
   public:
     StmtResult ParseStatementOrDeclaration(...) override;
     ExprResult ParseExpression(...) override;
     bool ParseTopLevelDecl(...) override;
     ...
   };
   ```
The methods listed above have been declared as `virtual` in the class `Parser`.
The implementations of these methods in `CaptureParser` handle syntax macros.
From the previous section we know that handling of syntax macros is triggered by one of the tokens `$`, `$$`, `$$$`.
When the methods `CaptureParser::Parse*` are done handling macro-specific parts of the source code, they defer to the corresponding methods in `Parser` for parsing of "normal" C/C++ code.

In Clang the building of ASTs is carried out by the `Sema` class.
Syntax macros introduce two new places where ASTs must be built:

1. the body of a syntax macro,
2. when a macro is invoked.

Functionality for building ASTs in these places is also added by deriving from the `Sema` class:
   ```
   class CaptureSema : public Sema {
     ...
   };
   ```
However, this time no existing methods in `Sema` have to be declared as `virtual`.
This is because `CaptureSema` is only used by `CaptureParser`, and whenever `CaptureParser` calls a method present in both `CaptureSema` and `Sema`, it can be decided statically which class's method implementation is to be called.
Thus no dynamic polymorphism, as facilitated by `virtual` methods, is required in this context.


## Bug reports & suggestion

Bugs related to syntax macros and suggestions for further development and
improvement should be submitted to norman.rink@tu-dresden.de.
