#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef unsigned long long ull;
ull pow_mod(ull n, ull k, ull m)
{
	ull mult = n% m;
	ull prod = 1;
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
	ull a, b, n;
	ull res;
	res = scanf("%llu%llu%llu", &a, &b, &n);
	assert(res == 3);
	if(b==1){
		printf("%llu", a);
    	return 0;
	}
	res = a % n;
	if (b & 1)
		res = pow_mod(a, res, n) % n;
	while(b > 0)
	{
		res = pow_mod(a, res, n) % n;
		b--;
	}
	
	printf("%llu", res);
	return 0;
}
