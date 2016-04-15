
int y = 42;

$$[Stmt] whileinc(Expr[int] VAL $ Stmt INC)
  while (($$$VAL) < y) $$$INC


int main() {
  int x = 3;
  $$[Stmt] ret(Expr[int] VAL) return $$$VAL;
    ;


  $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2
    ;

  $whileinc(x $ x+=1;)
  return x; // return '42'
}
