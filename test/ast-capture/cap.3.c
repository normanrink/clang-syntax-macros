
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

  return 0;
}
