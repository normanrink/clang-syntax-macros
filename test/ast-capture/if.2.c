
typedef int bool;

int main(int a) {
  $$[Stmt] IF(Expr[bool] cond $ Stmt body) if($$$cond) $$$body
    ;
  $$[Stmt] IFELSE(Expr[bool] cond $ Stmt then $ Stmt els) if ($$$cond) $$$then else $$$els
    ;

  $IFELSE ((a > 1) $
    $IF((a<3) $ ++a;) $
    {a += 40; a*=2;}
  )

  return a;
}
