
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 9

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=14 VarDecl | grep --after-context=14 res | FileCheck --check-prefix=VAR-DECL-res %s

int y = 42;

$$[Expr] add (Expr[int] x $ Expr[int] y)
  ($$$x) + ($$$y)
  ;

$$[Expr] fun (Expr[int] xx $ Expr[int] yy)
  $$[Expr] mul (Expr[int] aa)
    (($$$xx)*($$$aa))
  $add($$$xx $ $mul($$$yy))
  ;

int main() {
  int x = 3;
  int y = 2;

  int res = ($fun(x $ y));
// VAR-DECL-res:          | `-VarDecl 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> col:{{[0-9]+}} used res 'int' cinit
// VAR-DECL-res-NEXT:     |   `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |     `-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// VAR-DECL-res-NEXT:     |       |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |       | `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// VAR-DECL-res-NEXT:     |       |   `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// VAR-DECL-res-NEXT:     |       `-ParenExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |         `-ParenExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |           `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '*'
// VAR-DECL-res-NEXT:     |             |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |             | `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// VAR-DECL-res-NEXT:     |             |   `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// VAR-DECL-res-NEXT:     |             `-ParenExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// VAR-DECL-res-NEXT:     |               `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// VAR-DECL-res-NEXT:     |                 `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'y' 'int'

  return res; // return '9'
}
