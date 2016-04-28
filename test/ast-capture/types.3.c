
// RUN: %clang -o %t1 %s
// %t1 || echo $? | grep 42


int y = 42;

$$[WhileStmt] whileinc(Expr[int] VAL $ CompoundAssignOperator[int] INC)
  while (($$$VAL) < y) $$$INC;

$$[Stmt] custom(Stmt Arg) $$$Arg
  ;

$$[Stmt] fun(Expr[int] Val $ CompoundAssignOperator[int] inc)
  // Note that a 'WhileStmt' is indeed a 'Stmt', as required by the
  // list of formal arguments of "custom".
  $custom($whileinc($$$Val $ $$$inc))


int main() {
  int x = 3;

  $fun(x $ x+=1)
  return x; // return '42'
}
