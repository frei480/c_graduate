#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(unsigned long long n){
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	return 1;
}

void pn(unsigned long long n) {	
	unsigned long long prime_no=1, prime = 2;		  
	while (prime_no != n )
	{		
		if(is_prime(++prime))
			prime_no++;
	}
	printf("%llu", prime);
}

int main() {
	unsigned long long n = 0;	
	int res;
	res = scanf("%llu", &n);
	assert(res == 1);
	pn(n);
	return 0;
}

