
#include <stdio.h>

int main() {
  unsigned z = 42;
  $$[Stmt] xdecl (Expr[unsigned] in) unsigned x = ($$$in);
    $xdecl(z); // x = z
  
  $$[Stmt] ydecl (Expr[unsigned] init) unsigned y = x + ($$$init);
    ;

  $$[Stmt] yinc (Expr[unsigned] inc $ Stmt post) {y += ($$$inc); $$$post}
    ;

  int k = z + 17;
  $$[Expr] xplus (IntegerLiteral[unsigned] inc $ Expr[unsigned] inc2) x + ($$$inc2)
    ;
  $$[Expr] xpluss (Expr[unsigned] inc) x + ($$$inc)
  int j = ($xplus(2u $ 2u)); // j = x + 2

  printf("k=%d, j=%d\n", k, j); // '59', '44'

  $ydecl((unsigned)3)
  printf("x=%d, y=%d\n", x, y); // '42', '45'

  $$[Expr] zed z;
  $$[Stmt] direct_inc y+=2;
    ;

  $yinc($zed $ $direct_inc)
  printf("x=%d, y=%d\n", x, y); // '42', '89'

  x = ($xplus(3u $ z)); // x = x + z
  printf("x=%d, y=%d\n", x, y); // '84', '89'

  return 0;
}
