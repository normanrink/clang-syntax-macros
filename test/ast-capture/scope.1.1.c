
// RUN: %clang_cc1 -verify %s

int y = 42;

$$[Stmt] ret(DeclRefExpr[int] VAL) // expected-error {{failed to parse AST node}}
  return y + ($$$VAL);
  ;
// Parsing the 'return' statement fails since the "Sema" phase detects the absence 
// of a function context around the the 'return' statement. Consequently, "Sema"
// returns a 'StmtError()', which the "CaptureParser" notices as a 'nullptr'.

int main() {
  int y = 1;
  $ret(y) // return the 'global' y plus the 'local' y, i.e. 42+1 = 43
}
