
int y = 42;

$$[stmt] whileinc(expr[int] VAL $ stmt INC)
  while (($$$VAL) < y) $$$INC


int main() {
  int x = 3;
  $$[stmt] ret(expr[int] VAL) return $$$VAL;
    ;


  $$[expr] add2(expr[int] VAL) ($$$VAL)+2
    ;

  $whileinc(x $ x+=1;)
  return x;
}
