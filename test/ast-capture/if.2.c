
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT-0-ARGS %s
// RUN: %t1 arg1 | FileCheck --check-prefix=OUTPUT-1-ARGS %s
// RUN: %t1 arg1 arg2 | FileCheck --check-prefix=OUTPUT-2-ARGS %s
// RUN: %t1 arg1 arg2 arg3 | FileCheck --check-prefix=OUTPUT-3-ARGS %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=16 IfStmt | FileCheck --check-prefix=IF %s

#include <stdio.h>

typedef int bool;

int main(int a, char **argv) {
  $$[Stmt] IF(Expr[bool] cond $ Stmt body) if($$$cond) $$$body
    ;
  $$[Stmt] IFELSE(Expr[bool] cond $ Stmt then $ Stmt els) if ($$$cond) $$$then else $$$els
    ;

  $IFELSE ((a > 1) $
    $IF((a<3) $ ++a;) $
    {a += 40; a*=2;}
  )

  printf("%d\n", a);
// OUTPUT-0-ARGS: 82
// OUTPUT-1-ARGS: 3
// OUTPUT-2-ARGS: 3
// OUTPUT-3-ARGS: 4
  return 0;
}

// IF:          |-IfStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// IF-NEXT:     | |-<<<NULL>>>
// IF-NEXT:     | |-ParenExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// IF-NEXT:     | | `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '>'
// IF-NEXT:     | |   |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// IF-NEXT:     | |   | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | |   `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 1
// IF-NEXT:     | |-IfStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// IF-NEXT:     | | |-<<<NULL>>>
// IF-NEXT:     | | |-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int'
// IF-NEXT:     | | | `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '<'
// IF-NEXT:     | | |   |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// IF-NEXT:     | | |   | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | | |   `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 3
// IF-NEXT:     | | |-UnaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' prefix '++'
// IF-NEXT:     | | | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     | | `-<<<NULL>>>
// IF-NEXT:     | `-CompoundStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}>
// IF-NEXT:     |   |-CompoundAssignOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+=' ComputeLHSTy='int' ComputeResultTy='int'
// IF-NEXT:     |   | |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     |   | `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 40
// IF-NEXT:     |   `-CompoundAssignOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '*=' ComputeLHSTy='int' ComputeResultTy='int'
// IF-NEXT:     |     |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue ParmVar 0x{{[0-9a-f]+}} 'a' 'int'
// IF-NEXT:     |     `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 2

