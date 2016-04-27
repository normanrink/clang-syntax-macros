
// RUN: %clang -c -Xclang -verify -Xclang -ast-dump %s 1> %t
// RUN: grep --after-context=16 anon %t | FileCheck --check-prefix=ANON %s

int y = 42;

int anon() {
  // need a function context for 'return' statement:
  $$[Stmt] retinl(Expr[int] VAL)
    {
      // Define another 'Expr':
      $$[Expr] addinl(Expr[int] VAL $ Expr[int] INC) ($$$VAL)+($$$INC)
        ;
      // And another 'Expr':
      $$[Expr] add3(Expr[int] VAL) ($$$VAL)+3
        ;
      // Now for the actual 'Stmt':
      return $addinl($$$VAL $ $add3(y));
    }
    ;

  $retinl(y)
}
// ANON:      |-FunctionDecl 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}> line:{{[0-9]+}}:{{[0-9]+}} anon 'int ()'
// ANON-NEXT: | `-CompoundStmt 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |   |-NullStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |   `-CompoundStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |     |-NullStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |     |-NullStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |     `-ReturnStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// ANON-NEXT: |       `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// ANON-NEXT: |         |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// ANON-NEXT: |         | `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// ANON-NEXT: |         |   `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'y' 'int'
// ANON-NEXT: |         `-ParenExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// ANON-NEXT: |           `-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// ANON-NEXT: |             |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' <LValueToRValue>
// ANON-NEXT: |             | `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' lvalue
// ANON-NEXT: |             |   `-DeclRefExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'y' 'int'
// ANON-NEXT: |             `-IntegerLiteral 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' 3


int main() {
  int x = 3;
  $$[Stmt] ret(Expr[int] VAL) return $$$VAL;
    ;


  $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2
    ;


  y = 1;
  $retinl(x)
// expected-error@54 {{expected ')'}}
// expected-error@54 {{capture 'retinl' not defined}}
// expected-note@54 {{to match this '('}}
}
