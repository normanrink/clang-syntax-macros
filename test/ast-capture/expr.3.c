
int y = 42;

int anon() {
  // need a function context for 'return' statement:
  $$[stmt] retinl(expr[int] VAL)
    {
      // Define another 'expr':
      $$[expr] addinl(expr[int] VAL $ expr[int] INC) ($$$VAL)+($$$INC)
        ;
      // And another 'expr':
      $$[expr] add3(expr[int] VAL) ($$$VAL)+3
        ;
      // Now for the actual 'stmt':
      return $addinl($$$VAL $ $add3(y));
    }
    ;

  $retinl(y)
}


int main() {
  int x = 3;
  $$[stmt] ret(expr[int] VAL) return $$$VAL;
    ;


  $$[expr] add2(expr[int] VAL) ($$$VAL)+2
    ;


  y = 1;
  $retinl(x)
}
