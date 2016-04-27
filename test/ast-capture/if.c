
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT-0-ARGS %s
// RUN: %t1 arg1 | FileCheck --check-prefix=OUTPUT-1-ARGS %s
// RUN: %t1 arg1 arg2 | FileCheck --check-prefix=OUTPUT-2-ARGS %s
// RUN: %t1 arg1 arg2 arg3 | FileCheck --check-prefix=OUTPUT-3-ARGS %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=12 IfStmt | FileCheck --check-prefix=IF %s

#include <stdio.h>

int main(int a, char **argv) {
  $$[Stmt] IF(Stmt body) if(a < 3) $$$body
    ;

  if (a > 1)
    $IF(++a;)
  else
    a += 40;

  printf("%d\n", a);
// OUTPUT-0-ARGS: 41
// OUTPUT-1-ARGS: 3
// OUTPUT-2-ARGS: 3
// OUTPUT-3-ARGS: 4
  return 0;
}
// IF:          |-IfStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// IF-NEXT:     | |-<<<NULL>>>
// IF-NEXT:     | |-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '>'
// IF-NEXT:     | | |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// IF-NEXT:     | | | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | | `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 1
// IF-NEXT:     | |-IfStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// IF-NEXT:     | | |-<<<NULL>>>
// IF-NEXT:     | | |-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '<'
// IF-NEXT:     | | | |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// IF-NEXT:     | | | | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | | | `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 3
// IF-NEXT:     | | |-UnaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' prefix '++'
// IF-NEXT:     | | | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | | `-<<<NULL>>>
// IF-NEXT:     | `-CompoundAssignOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+=' ComputeLHSTy='int' ComputeResultTy='int'
// IF-NEXT:     |   |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     |   `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 40

