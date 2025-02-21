#include <stdio.h>
#include <assert.h>

// ... Q2
int factorielle(int k)
{
  int i, res = 1;
  assert(k > 1);
  for(i = 2; i <= k; i++)
    res *= i;
  return res;
}

int
facto(int fk, int k)
{
  return fk * (2*k+1) * (2*k+2);
}

float
pow_x(float xk, float x)
{
  return xk * (x*x);
}

int
main(void)
{
  float x, res, fact, sign, pow;
  int i, i_fact, n = 0;
  
  // ... Q1
  printf("Entrez une valeur de n= ");
  scanf("%d", &n);
  printf("Entrez une valeur de x= ");
  scanf("%f", &x);
  // ...
  pow = x * x;
  res = 1;
  fact = 2;
  i_fact = 2;
  sign = -1;
  i = 1;
  while(i <= n) {
    res = res + sign * (pow / fact);
    pow = pow * (x * x);
    fact = fact * (i_fact + 1) * (i_fact + 2);
    i_fact += 2;
    sign = -sign;
    i ++;
  }
  printf("cos(x)= %f\n", res);

  // ... Q3
  pow = x * x;
  res = 1;
  sign = -1;
  i = 1;
  while(i <= n) {
    res = res + sign * (pow / factorielle(2*i));
    pow = pow * (x * x);
    sign = -sign;
    i ++;
    printf("cos(x)= %f [%f %d]\n", res, pow/(x*x), factorielle(2*(i-1)));
  }
  // printf("cos(x)= %f\n", res);

  // ... Q4
  float pow_xk = 1;
  int fact_k = 1;
  res = 1;
  sign = 1;
  i = 1;
  while(i <= n) {
    pow_xk = pow_x(pow_xk, x);
    fact_k = facto(fact_k, i-1);
    sign = -sign;
    res = res + sign * pow_xk/fact_k;
    i ++;
    printf("cos(x)= %f [%f %d]\n", res, pow_xk, fact_k);
  }
  
  
  return 0;
}
