#include <stdio.h>

float suite(int n)
{
    if (n == 0)
        return 2.0;
    else
    {
      double prev = suite(n - 1);
      return 0.5 *(prev - 1 + 3 / prev - 1);
    }
}


int main()
{
  int n = 4;
  float res;
  
  res = suite(n);
  
  
    return 0;
}