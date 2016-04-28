
// RUN: %clang -c -Xclang -verify %s

int main() {
  int x = 3;
  $$[Stmt] ret(Expr[int] VAL) return $$$VALL; // expected-error {{placeholder 'VALL' not defined}}
    ;

  $ret(x)
}
