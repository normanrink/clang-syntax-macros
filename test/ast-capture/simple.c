
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s

#include <stdio.h>

$$[Expr] add (Expr[int] var $ IntegerLiteral[int] num) ($$$var) + ($$$num)
  ;

int simple() {
  $$[DeclStmt] init () int x = 1;
    ;
  
  $init

  x = ($add(x $ 41));
  return x;
}

int main() {
  printf("%d", simple()); // '42'
// OUTPUT: 42
  return 0;
}
