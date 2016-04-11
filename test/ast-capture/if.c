
int main(int a) {
  $$[stmt] IF(stmt body) if(a < 3) $$$body

  if (a > 1)
    $IF(++a;)
  else
    a += 40;

  return a;
}
