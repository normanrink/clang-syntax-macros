 
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 14

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
  int y = 17;

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

  $sub(3); // 'local' y = (3+y) - (3+3) = (3+17) - 6 = 14
  return y; // return 'local' y, i.e. '14'
}
