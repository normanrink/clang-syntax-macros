
// FIXME: This test passes for the wrong reasons, executing '%t1' returns '0'.
// This is because capturing 'ret' leads to a (silent) 'StmtError' in the "Sema"
// phase, which in turn is caused  by the absence of a function context around
// the 'return' statement.

// RUN: %clang -o %t1 %s
// RUN: %t1 || echo $? | grep 43

int y = 42;

$$[Stmt] ret(DeclRefExpr[int] VAL)
  return y + ($$$VAL);
  ;

int main() {
  int y = 1;
  $ret(y) // return the 'global' y plus the 'local' y, i.e. 42+1 = 43
}
