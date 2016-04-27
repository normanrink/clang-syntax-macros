
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=7 VarDecl | grep --after-context=7 j_var | FileCheck --check-prefix=VAR-DECL-j %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=6 VarDecl | grep --after-context=6 y_var | FileCheck --check-prefix=VAR-DECL-y %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=9 line:20:50 | FileCheck --check-prefix=y-INC %s
// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=8 line:68:3 | FileCheck --check-prefix=x-ASSIGN %s
 
#include <stdio.h>

int main() {
  unsigned z = 42;
  $$[Stmt] xdecl (Expr[unsigned] in) unsigned x = ($$$in);
    $xdecl(z); // x = z
  
  $$[Stmt] ydecl (Expr[unsigned] init) unsigned y_var = x + ($$$init);
    ;

  $$[Stmt] yinc (Expr[unsigned] inc $ Stmt post) {y_var += ($$$inc); $$$post}
    ;

  int k = z + 17;
  $$[Expr] xplus (IntegerLiteral[unsigned] inc $ Expr[unsigned] inc2) x + ($$$inc2)
    ;
  $$[Expr] xpluss (Expr[unsigned] inc) x + ($$$inc)
  int j_var = ($xplus(2u $ 2u)); // j = x + 2
// VAR-DECL-j:          | `-VarDecl 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> col:{{[0-9]+}} used j_var 'int' cinit
// VAR-DECL-j-NEXT:     |   `-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'int' <IntegralCast>
// VAR-DECL-j-NEXT:     |     `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// VAR-DECL-j-NEXT:     |       `-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+'
// VAR-DECL-j-NEXT:     |         |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' <LValueToRValue>
// VAR-DECL-j-NEXT:     |         | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'unsigned int'
// VAR-DECL-j-NEXT:     |         `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// VAR-DECL-j-NEXT:     |           `-IntegerLiteral 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'unsigned int' 2
  printf("k=%d, j=%d\n", k, j_var); // '59', '44'
// OUTPUT: k=59, j=44

  $ydecl((unsigned)3)
// VAR-DECL-y:          | `-VarDecl 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> col:{{[0-9]+}} used y_var 'unsigned int' cinit
// VAR-DECL-y-NEXT:     |   `-BinaryOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+'
// VAR-DECL-y-NEXT:     |     |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' <LValueToRValue>
// VAR-DECL-y-NEXT:     |     | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'unsigned int'
// VAR-DECL-y-NEXT:     |     `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// VAR-DECL-y-NEXT:     |       `-CStyleCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' <IntegralCast>
// VAR-DECL-y-NEXT:     |         `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 3
  printf("x=%d, y=%d\n", x, y_var); // '42', '45'
// OUTPUT-NEXT: x=42, y=45

  $$[Expr] zed z;
  $$[Stmt] direct_inc y_var+=2;
    ;

  $yinc($zed $ $direct_inc)
// y-INC:          |-CompoundStmt 0x{{[0-9a-f]+}} <line:20:50, col:{{[0-9]+}}>
// y-INC-NEXT:     | |-CompoundAssignOperator 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+=' ComputeLHSTy='unsigned int' ComputeResultTy='unsigned int'
// y-INC-NEXT:     | | |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'y_var' 'unsigned int'
// y-INC-NEXT:     | | `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// y-INC-NEXT:     | |   `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'unsigned int' <LValueToRValue>
// y-INC-NEXT:     | |     `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'z' 'unsigned int'
// y-INC-NEXT:     | `-CompoundAssignOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+=' ComputeLHSTy='unsigned int' ComputeResultTy='unsigned int'
// y-INC-NEXT:     |   |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'y_var' 'unsigned int'
// y-INC-NEXT:     |   `-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' <IntegralCast>
// y-INC-NEXT:     |     `-IntegerLiteral 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'int' 2          
  printf("x=%d, y=%d\n", x, y_var); // '42', '89'
// OUTPUT-NEXT: x=42, y=89

  x = ($xplus(3u $ z)); // x = x + z
// x-ASSIGN:          |-BinaryOperator 0x{{[0-9a-f]+}} <line:68:3, col:{{[0-9]+}}> 'unsigned int' '='
// x-ASSIGN-NEXT:     | |-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'unsigned int'
// x-ASSIGN-NEXT:     | `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// x-ASSIGN-NEXT:     |   `-BinaryOperator 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int' '+'
// x-ASSIGN-NEXT:     |     |-ImplicitCastExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' <LValueToRValue>
// x-ASSIGN-NEXT:     |     | `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'x' 'unsigned int'
// x-ASSIGN-NEXT:     |     `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'unsigned int'
// x-ASSIGN-NEXT:     |       `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'unsigned int' <LValueToRValue>
// x-ASSIGN-NEXT:     |         `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'unsigned int' lvalue Var 0x{{[0-9a-f]+}} 'z' 'unsigned int'
  printf("x=%d, y=%d\n", x, y_var); // '84', '89'
// OUTPUT-NEXT: x=84, y=89

  return 0;
}
