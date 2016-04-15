
#include <stdio.h>

int main() {
  $$[Stmt] ydecl (Expr[unsigned] init) unsigned y = 42 + ($$$init);
    ;

  $$[Stmt] yinc (CStyleCastExpr[unsigned] inc) y += ($$$inc);
    ;

  $ydecl(3u) // y = 42 + 3
  printf("y=%d\n", y); // '45'

  $yinc((unsigned)3)
  printf("y=%d\n", y); // '48'

  return 0;
}
