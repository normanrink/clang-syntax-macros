
int y = 42;

$$[Stmt] sub(Expr[int] VAL)
  {
    // Define another 'Expr':
    $$[Expr] addinl(Expr[int] VAL $ Expr[int] INC) ($$$VAL)+($$$INC)
      ;
    // And another 'Expr':
    $$[Expr] add3(Expr[int] VAL) ($$$VAL)+3
      ;
    // Now for the actual 'Stmt':
    y = ($addinl($$$VAL $ y))-($add3($$$VAL));
  }
  ;

int main() {
  int y = 1;

  $$[Stmt] sub(Expr[int] VAL)
    {
      // Define another 'Expr':
      $$[Expr] addinl(Expr[int] VAL $ Expr[int] INC) ($$$VAL)+($$$INC)
        ;
      // And another 'Expr':
      $$[Expr] add3(Expr[int] VAL) ($$$VAL)+3
        ;
      // Now for the actual 'Stmt':
      y = ($addinl($$$VAL $ y))-($add3($$$VAL));
    }
    ;

  $sub(3); // 'local' y = (3+y) - (3+3) = (3+1) - 6 = -2
  return y; // return '-2'
}
