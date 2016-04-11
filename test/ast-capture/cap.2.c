
#include <stdio.h>

int main() {
  $$[stmt, ;] ydecl (expr init) unsigned y = 42 + ($$$[unsigned]init);

  $$[stmt] yinc (expr inc) y += ($$$[unsigned]inc);

  $ydecl((unsigned)3)
  printf("y=%d\n", y);

  $yinc(3)
  printf("y=%d\n", y);

  return 0;
}
