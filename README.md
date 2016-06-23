

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

TODO


## Bug reports & suggestion

Bugs related to syntax macros and suggestions for further development and
improvement should be submitted to norman.rink@tu-dresden.de.
