
int y = 42;

$$[Expr] add (Expr[int] x $ Expr[int] y)
  ($$$x) + ($$$y)
  ;

$$[Expr] fun (Expr[int] xx $ Expr[int] yy)
  $$[Expr] mul (Expr[int] aa)
    (($$$xx)*($$$aa))
  $add($$$xx $ $mul($$$yy))
  ;

int main() {
  int x = 3;
  int y = 2;

  int res = ($fun(x $ y));
  return res;
}
