
int main() {
  int x = 3;

  $$[stmt] ret(expr[int] VAL) $$[expr] add2(expr[int] VAL) ($$$VAL)+2   return $add2($$$VAL);

  $ret(x*2)
}
