#include <stdio.h>
#include <math.h>

int
main(void)
{
  float a, b, h, xi, s1, s2, s3, s4, res = 0.f;
  int n, i;
  
  printf("Lire a et b= ");
  scanf("%f%f", &a, &b);
  
  printf("Lire n= ");
  scanf("%d", &n);
  
  // ... non sanctionnee
  if(a > b) {
    float tmp;
    tmp = a;
    a = b;
    b = tmp;
  }
  // ...
  
  h = (b - a)/n;
   
  // ... s1 = f(x0), x0 = a
  s1 = sinf(a);

  // ... s2 = 2 * sum_{i = 1}^{n/2-1} f(x2i)
  s2 = 0.f;
  for(i = 1; i <= n/2-1; i++) {
    xi = a + 2 * i * h;
    s2 += sinf(xi);
  }
  s2 *= 2.f;

  // ... s3 = 4 * sum_{i = 1}^{n/2} f(x2i-1)
  s3 = 0.f;
  for(i = 1; i <= n/2; i++) {
    xi = a + (2 * i - 1) * h;
    s3 += sinf(xi);
  }
  s4 *= 4.f;

  // ... s4 = f(xn), avec xn = a + n * h
  s4 = sinf(a+n*h);

  // ... res = h/3 * (s1 + s2 + s3 + s4);
  res = (h/3.f) * (s1 + s2 + s3 + s4);
  printf("... integral: %f\n", res);

  return 0;
}
