/*
n2 + n + 41, открытая Эйлером, генерирует для 0 <= n <= 39

n2 + an + b, в предположеннии, что |a| < N и |b| < N
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
	int i;
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	
	return 1;
}
int main() {
	//struct sieve_t sv;
    int n=0, N = 0;
    int a, b, digit;
	int res;
    res = scanf("%d", &N);
    assert(res == 1);
    for(a=-n; a < N; ++a)
        for(b=-n; b < N; ++b)
            digit = n*n + a*n + b;   
    
    

    

    printf("%d\n", n);
    
   return 0;
}