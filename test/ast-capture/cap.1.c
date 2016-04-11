
#include <stdio.h>

int main() {
  unsigned z = 42;
  $$[stmt, self] xdecl (expr in=z;) unsigned x = ($$$[unsigned]in);
  $$[stmt] ydecl (expr init) unsigned y = x + ($$$[unsigned]init);

  $$[stmt] yinc (expr inc, stmt post=++y;) {y += ($$$[unsigned]inc); $$$post}

  int k = ($$[expr, z+17] xplus (inc, inc2) x + ($$$[unsigned]inc2));
  int j = ($$[expr, self] xpluss (inc=2) x + ($$$[unsigned]inc));
  printf("k=%d, j=%d\n", k, j);

  $ydecl((unsigned)3)
  printf("x=%d, y=%d\n", x, y);

  $$[expr, 0] zed z;
  $$[stmt] direct_inc y+=2;
  $yinc(($zed) $ $direct_inc)
  printf("x=%d, y=%d\n", x, y);

  x = ($xplus(3 $ z));
  printf("x=%d, y=%d\n", x, y);

  return 0;
}
