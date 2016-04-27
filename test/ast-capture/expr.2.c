
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 8

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=7 ReturnStmt | FileCheck --check-prefix=RETURN %s
 
int main() {
  int x = 3;

  $$[Stmt] ret(Expr[int] VAL) $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2   return $add2($$$VAL);

  $ret(x*2) // return '8'
// RETURN:          `-ReturnStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}>
// RETURN-NEXT:       `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// RETURN-NEXT:         |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// RETURN-NEXT:         | `-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '*'
// RETURN-NEXT:         |   |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// RETURN-NEXT:         |   | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// RETURN-NEXT:         |   `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 2
// RETURN-NEXT:         `-IntegerLiteral 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' 2
}
