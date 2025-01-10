#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {
unsigned long long q;
	if (y > x)
	{
    x = y^x;
		y = x^y;
    x = y^x;
	}	
   

	while(x % y)
	{
		q = x % y;
		x = y; 
		y = q;
	}
  return y;
}


int main() {
	unsigned long long x = 0, y = 0, g;  
	long long x_in=0, y_in=0;
	int res;
  
  res = scanf("%lld %lld", &x_in, &y_in);
	x = abs(x_in);
	y = abs(y_in);
  assert(res == 2);
	
 	g = gcd(x, y);
  printf("%llu\n", g);
  return 0;
}

