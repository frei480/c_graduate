#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(unsigned long long int x, unsigned long long int m)
{
	unsigned long long a = 0, b = 1, n = 2, tmp;
	if (x == 0) 
		return 0ull;
	
	for(n = 2; n <= x; ++n)
	{
		tmp = b;
		b = (a+b) %m ;
		a = tmp;
	}
	return b;
}

int main() 
{
	unsigned long long fibm;
	unsigned long long x, m;

	int res;
  res = scanf("%llu %llu", &x, &m);
	assert(res == 2);

  fibm =  fib(x, m);
  printf("%llu", fibm);
	return 0;
}
//0 1 1 2 3 5 8 13 21 34
