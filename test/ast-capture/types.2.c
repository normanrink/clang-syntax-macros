
// RUN: %clang -c -Xclang -verify %s


int y = 42;

$$[Stmt] whileinc(Expr[int] VAL $ CompoundAssignOperator[int] INC)
  while (($$$VAL) < y) $$$INC; // expected-warning {{expression result unused}}

$$[WhileStmt] custom(WhileStmt Arg) $$$Arg
  ;

$$[Stmt] fun(Expr[int] Val $ CompoundAssignOperator[int] inc)
  $custom($$$Val) // expected-error {{wrong AST node type: 'Val' is a 'Expr', expected 'WhileStmt'}}


int main() {
  int x = 3;

  $fun(x $ x+=1)
  return 0;
}
