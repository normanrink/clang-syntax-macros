
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 39
 
int y = 42;

$$[Stmt] sub(Expr[int] VAL)
  {
    // Define another 'Expr':
    $$[Expr] addinl(Expr[int] VAL $ Expr[int] INC) ($$$VAL)+($$$INC)
      ;
    // And another 'Expr':
    $$[Expr] add3(Expr[int] VAL) ($$$VAL)+3
      ;
    // Now for the actual 'stmt':
    y = ($addinl($$$VAL $ y))-($add3($$$VAL));
  }
  ;

int main() {
  $sub(3); // 'global' y = (3+y) - (3+3) = (3+42) - 6 = 39
  return y; // return '39'
}
