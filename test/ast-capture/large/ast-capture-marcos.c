
// AST-capture macros "subs" and "add".

static float y = 17.0;

const int N = 100;

int a[N];
int b[N];
int c[N];
int d[N];

int main() {

  int x = 0;
  $$[Expr] subs (Expr[int*] A $ Expr[int*] B $ Expr[int] i) ($$$A)[ ($$$B) [($$$i)] ]
    ;

  for (int i = 0; i < N; i++) {
    a[i] = i;
    b[i] = i;
    c[i] = i;
    d[i] = i;
  }

  int *ap = a;
  int *bp = b;
  int *cp = c;
  int *dp = d;

  int o1 = 1, o2 = 2;

  int y = 0;
  $$[Expr] add (Expr[int*] A $ Expr[int] off1 $ Expr[int] off2)
      ( ($$$A) + (2*($$$off1)*
        (1 + 3*(($$$off2)*(($$$off1)
                                + (($$$off1) ) * (($$$off2)
                                                          +(4*(($$$off1)+($$$off2)))
                                                          )
                                )
                )
         )
                        )
       )
          ;

  int k = N-1;
  int res = ($subs(ap $ $add(bp $ o1 $ o2) $ k));

  res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
  {
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));








    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    // again

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));








    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));




    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));


    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));

    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
    res = ($subs(cp $ $add(dp $ o1 $ o2) $ k));
  }
  return res;
}
