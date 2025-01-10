#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void gcd(unsigned long long x, 
         unsigned long long y) {
	unsigned long long q;
  while((x > 0) && (y > 0))
	{
		q = x % y;
	 	printf("%lld ", x/y);
		x = y; 
		y = q;
	}  
}

int main() {
	unsigned long long x = 0, y = 0;  
	long long x_in=0, y_in=0;
	int res;
  
  res = scanf("%lld %lld", &x_in, &y_in);
	x = abs(x_in);
	y = abs(y_in);
  assert(res == 2);
	
 	gcd(x, y);
  
  return 0;
}

