
#include <stdio.h>

int main() {
  unsigned z = 42;
  $$[stmt, self] xdecl (in=z;) unsigned x = ($$$[unsigned]in);
  $$[stmt] ydecl (init) unsigned y = x + ($$$[unsigned]init);

  $$[stmt] yinc (inc) y += ($$$[unsigned]inc);

  int k = ($$[expr, z+17] xplus (inc) x + ($$$[unsigned]inc));
  int j = ($$[expr, self] xpluss (inc=2) x + ($$$[unsigned]inc));
  printf("k=%d, j=%d\n", k, j);

  $ydecl((unsigned)3;)
  printf("x=%d, y=%d\n", x, y);

  $yinc(z;)
  printf("x=%d, y=%d\n", x, y);

  x = ($xplus(z));
  printf("x=%d, y=%d\n", x, y);

  return 0;
}
