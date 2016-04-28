
// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 43

int y = 42;

int main() {
  $$[Stmt] ret(DeclRefExpr[int] VAL)
    return y + ($$$VAL); // captures the 'global' y
    ;
  int y = 1;
  $ret(y) // return the 'global' y plus the 'local' y, i.e. 42+1 = 43
}
