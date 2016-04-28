
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 85

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=10 WhileStmt | FileCheck --check-prefix=WHILE %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=7 ReturnStmt | FileCheck --check-prefix=RETURN %s

int y = 42;

$$[Stmt] whileinc(Expr[int] VAL $ CompoundAssignOperator[int] INC)
  while (($$$VAL) < y) $$$INC;

$$[WhileStmt] custom(WhileStmt Arg) $$$Arg
  ;

$$[Stmt] fun(Expr[int] Val $ CompoundAssignOperator[int] inc)
  $custom($whileinc($$$Val $ $$$inc))


int main() {
  int x = 3;
  $$[ReturnStmt] ret(BinaryOperator[int] VAL) return $$$VAL;
    ;

  $fun(x $ x+=1)
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

  $ret(x+1+x) // return '85'
// RETURN:          `-ReturnStmt 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, line:{{[0-9]+}}:{{[0-9]+}}>
// RETURN-NEXT:       `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// RETURN-NEXT:         |-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' '+'
// RETURN-NEXT:         | |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// RETURN-NEXT:         | | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
// RETURN-NEXT:         | `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 1
// RETURN-NEXT:         `-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' <LValueToRValue>
// RETURN-NEXT:           `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'int'
}
