
// RUN: %clang -o %t1 %s
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

int y = 42;

$$[Expr] add (Expr[int] x $ Expr[int] y)
  ($$$x) + ($$$y)
  ;

// Check that the scoping is correct:
// 1. Arguments 'x' and 'y' here should not interfere with the ones from the 'add' macro.
// 2. Variable 'y' in the bodies of macros 'fun' and 'mul' should reference the global variable 'y'. 
// Hence the macro 'fun(a $ b)' computes this: b + mul(global_y) = b + global_y*global_y.
$$[Expr] fun (Expr[int] x $ Expr[int] y)
  $$[Expr] mul (Expr[int] y)
    (y*($$$y))
  $add($$$y $ $mul(y))
  ;

int main() {
  int x = 3;
  int y = 2;

  int res = ($fun(x $ y));

  printf("%d\n", res);
// OUTPUT: 1766
  return 0;
}
