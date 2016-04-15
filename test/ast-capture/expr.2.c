
int main() {
  int x = 3;

  $$[Stmt] ret(Expr[int] VAL) $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2   return $add2($$$VAL);

  $ret(x*2) // return '8'
}
