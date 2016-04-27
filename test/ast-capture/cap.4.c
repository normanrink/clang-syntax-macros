
// RUN: %clang -c -Xclang -verify %s

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

  $$[Expr] len (Expr[struct B] X) ($$$X).length;

  printf("%d\n", ($len(a)) ); // expected-error {{passing 'struct A' to parameter of incompatible type 'struct B'}}

  return 0;
}
