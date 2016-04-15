
int main(int a) {
  $$[Stmt] IF(Stmt body) if(a < 3) $$$body
    ;

  if (a > 1)
    $IF(++a;)
  else
    a += 40;

  return a;
}
