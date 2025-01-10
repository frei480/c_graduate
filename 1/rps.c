#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned pow_mod(unsigned n, unsigned k, unsigned m)
{
	unsigned mult = n % m;
	unsigned prod = 1;
	while (k > 0)
	{
		if((k % 2) == 1)
		{
			prod = (prod * mult) % m;
			k--;
		}
		mult = (mult*mult) % m;
		k/=2;
	}
	return prod;
}
int main()
{
	unsigned a, b, n;
	unsigned res;
	res = scanf("%u%u%u", &a, &b, &n);
	assert(res == 3);
	res = a % n;
	while(b > 0)
	{
		res =	pow_mod(res, b, n);
		b--;
	}
	printf("%u\n", res);
	return 0;
}
