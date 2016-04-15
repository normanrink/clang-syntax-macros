
int y = 42;

int anon() {
  // need a function context for 'return' statement:
  $$[Stmt] retinl(Expr[int] VAL)
    {
      // Define another 'Expr':
      $$[Expr] addinl(Expr[int] VAL $ Expr[int] INC) ($$$VAL)+($$$INC)
        ;
      // And another 'Expr':
      $$[Expr] add3(Expr[int] VAL) ($$$VAL)+3
        ;
      // Now for the actual 'Stmt':
      return $addinl($$$VAL $ $add3(y));
    }
    ;

  $retinl(y)
}


int main() {
  int x = 3;
  $$[Stmt] ret(Expr[int] VAL) return $$$VAL;
    ;


  $$[Expr] add2(Expr[int] VAL) ($$$VAL)+2
    ;


  y = 1;
  $retinl(x)
}
