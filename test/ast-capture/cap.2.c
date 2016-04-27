
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=5 VarDecl | grep --after-context=5 y_var | FileCheck --check-prefix=VAR-DECL-y %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=4 line:14:48 | FileCheck --check-prefix=y-INC %s
 
#include <stdio.h>

int main() {
  $$[Stmt] ydecl (Expr[unsigned] init) unsigned y_var = 42 + ($$$init);
    ;

  $$[Stmt] yinc (CStyleCastExpr[unsigned] inc) y_var += ($$$inc);
    ;

  $ydecl(3u) // y = 42 + 3
// VAR-DECL-y:          | `-VarDecl 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> col:{{[0-9]+}} used y_var 'unsigned int' cinit
// VAR-DECL-y-NEXT:     |   `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+'
// VAR-DECL-y-NEXT:     |     |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' <IntegralCast>
// VAR-DECL-y-NEXT:     |     | `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 42
// VAR-DECL-y-NEXT:     |     `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// VAR-DECL-y-NEXT:     |       `-IntegerLiteral 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'unsigned int' 3
  printf("y=%d\n", y_var); // '45'
// OUTPUT: y=45

  $yinc((unsigned)3)
// y-INC:          |-CompoundAssignOperator 0x{{[0-9a-f]+}} <line:14:48, col:{{[0-9]+}}> 'unsigned int' '+=' ComputeLHSTy='unsigned int' ComputeResultTy='unsigned int'
// y-INC-NEXT:     | |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'y_var' 'unsigned int'
// y-INC-NEXT:     | `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// y-INC-NEXT:     |   `-CStyleCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' <IntegralCast>
// y-INC-NEXT:     |     `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 3          
  printf("y=%d\n", y_var); // '48'
// OUTPUT: y=48

  return 0;
}
