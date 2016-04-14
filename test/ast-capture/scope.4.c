
int y = 42;

$$[stmt] sub(expr[int] VAL)
  {
    // Define another 'expr':
    $$[expr] addinl(expr[int] VAL $ expr[int] INC) ($$$VAL)+($$$INC)
      ;
    // And another 'expr':
    $$[expr] add3(expr[int] VAL) ($$$VAL)+3
      ;
    // Now for the actual 'stmt':
    y = ($addinl($$$VAL $ y))-($add3($$$VAL));
  }
  ;

int main() {
  int y = 1;
  $sub(3); // 'global' y = (3+y) - (3+3) = (3+42) - 6 = 39
  return y; // return '1'
}
