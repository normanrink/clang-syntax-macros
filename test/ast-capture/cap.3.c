
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

  $$[expr, 0] len (X) ($$$[struct A]X).length;

  printf("%d\n", ($len(a)) );

  /* This will not work since the argument of 'len'
   *is expected to be a 'struct A':
   struct B b;
   b.length = 17;
   printf("%d\n", ($len(b)) );
   */

  return 0;
}
