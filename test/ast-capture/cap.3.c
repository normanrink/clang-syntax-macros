
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

// RUN: %clang -c -Xclang -ast-dump %s | grep --after-context=3 MemberExpr | grep --after-context=3 line:24:35 | FileCheck --check-prefix=MEMBER %s

#include <stdio.h>

struct A {
  int length;
  char *label;
};

struct B {
  struct B *next;
  int length;
  int id;
};

int main() {
  struct A a;
  a.length = 42;

  $$[Expr] len (Expr[struct A] X) ($$$X).length;

  printf("%d\n", ($len(a)) ); // '42'
// OUTPUT: 42
// MEMBER:          |   `-MemberExpr 0x{{[0-9a-f]+}} <line:24:35, col:{{[0-9]+}}> 'int' .length 0x{{[0-9a-f]+}}
// MEMBER-NEXT:     |     `-ParenExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}, col:{{[0-9]+}}> 'struct A':'struct A'
// MEMBER-NEXT:     |       `-ImplicitCastExpr 0x{{[0-9a-f]+}} <line:{{[0-9]+}}:{{[0-9]+}}> 'struct A':'struct A' <LValueToRValue>
// MEMBER-NEXT:     |         `-DeclRefExpr 0x{{[0-9a-f]+}} <col:{{[0-9]+}}> 'struct A':'struct A' lvalue Var 0x{{[0-9a-f]+}} 'a' 'struct A':'struct A'

  return 0;
}
