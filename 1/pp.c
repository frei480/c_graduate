#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


unsigned long long piz(unsigned long long m);
unsigned long long fib(unsigned long long x, unsigned long long m, 	unsigned long long * ptr )
{
	unsigned long long a = 0, b = 1, n = 2, tmp, cycle;
	
	cycle = piz(m);
	*ptr = cycle;
	x %=cycle;
	if (x==2 || x==1)
		return 1;
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

unsigned long long piz(unsigned long long m)
{
	unsigned long long a = 0, b = 1, n = 0, tmp;
	while(1)
	{
		tmp = b;
		b = (a+b) % m;
		a = tmp;
		n++;
		if(a ==0 && b == 1)
			break;
	}
	return n;
}

int main() 
{
	unsigned long long fibm, cycle=0ull;
	unsigned long long x, m;
	unsigned long long * ptr = &cycle;
	int res;
  res = scanf("%llu %llu", &x, &m);
	assert(res == 2);

  fibm =  fib(x, m, &cycle);
	
  printf("%llu %llu", fibm, cycle);
	return 0;
}
//0 1 1 2 3 5 8 13 21 34
