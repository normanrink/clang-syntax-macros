
// RUN: %clang %s -o %t1
// RUN: %t1 | FileCheck --check-prefix=OUTPUT %s
 
// Pre-processor macros "subs" and "add".

#include <stdio.h>

static float y = 17.0;

const int N = 100;

int a[N];
int b[N];
int c[N];
int d[N];

#define subs(A, B, i) (  (A)[ (B)[(i)] ]  )
#define add(A, off1, off2) (  (A) + (2*(off1)* \
                              (1+3*((off2)*((off1) \
                                            + (off1)*((off2) \
                                                          + (4*((off1)+(off2))) \
                                                          ) \
                                            )\
                                    )\
                               )\
                                    )\
                            )

int main() {

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

  int k = N-1;
  int res = subs(ap, add(bp, o1, o2), k);

  res = subs(cp, add(dp, o1, o2), k);
  {
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);








    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    // again

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);








    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);




    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);


    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);

    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
    res = subs(cp, add(dp, o1, o2), k);
  }
  printf("%d\n", res);
// OUTPUT: 81
  return 0;
}
