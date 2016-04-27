
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=10 WhileStmt | FileCheck --check-prefix=WHILE %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=1 ReturnStmt | FileCheck --check-prefix=RETURN %s

#include <stdio.h>

int y = 42;

$$[Stmt] whileinc(Expr[int] VAL $ Stmt INC)
  while (($$$VAL) < y) $$$INC


int main() {
  int x = 3;
  $$[Stmt] ret(Expr[int] VAL) return $$$VAL;
    ;


  $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2
    ;

  $whileinc(x $ x+=1;)
// WHILE:          |-WhileStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// WHILE-NEXT:     | |-<<<NULL>>>
// WHILE-NEXT:     | |-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '<'
// WHILE-NEXT:     | | |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// WHILE-NEXT:     | | | `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// WHILE-NEXT:     | | |   `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// WHILE-NEXT:     | | `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'int' <LValueToRValue>
// WHILE-NEXT:     | |   `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'y' 'int'
// WHILE-NEXT:     | `-CompoundAssignOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+=' ComputeLHSTy='int' ComputeResultTy='int'
// WHILE-NEXT:     |   |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// WHILE-NEXT:     |   `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 1

  printf("%d\n", x);
// OUTPUT: 42

  $ret(0)
// RETURN:          `-ReturnStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// RETURN-NEXT:       `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 0
}
