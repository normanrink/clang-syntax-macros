
int y = 42;

$$[Stmt] whileinc(Expr[int] VAL $ CompoundAssignOperator[int] INC)
  while (($$$VAL) < y) $$$INC;

$$[WhileStmt] custom(WhileStmt Arg) $$$Arg
  ;

$$[Stmt] fun(Expr[int] Val $ CompoundAssignOperator[int] inc)
  $custom($whileinc($$$Val $ $$$inc))


int main() {
  int x = 3;
  //$$[ReturnStmt] ret(BinaryOperator[int] VAL) return $$$VAL;
  //  ;

  $fun(x $ x+=1)
  //$ret(x+1+x)

    return 0;
}
