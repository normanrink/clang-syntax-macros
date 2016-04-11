
int main(int a) {
  $$[stmt] IF(expr cond, stmt body) if($$$[int]cond) $$$body
  $$[stmt] IFELSE(expr cond, stmt then, stmt els) if ($$$[int]cond) $$$then else $$$els

  $IFELSE ((a > 1) $
    $IF((a<3) $ ++a;) $
    {a += 40; a*=2;}
  )

  return a;
}
