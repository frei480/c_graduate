/*
int is_prime(int n){
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	return 1;
}
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
    int n;           
    unsigned char *s;
};


void fill_sieve(struct sieve_t *sv) {    
    unsigned long long i, j;    
    sv->s[0] |= (1 << 0);
    sv->s[0] |= (1 << 1);
    
    for (i = 2; i * i < sv->n; i++) {
        if (!(sv->s[i / 8] & (1 << (i % 8)))) { 
            for (j = i * i; j <= sv->n; j += i) {
                sv->s[j / 8] |= (1 << (j % 8)); 
            }
        }
    }
}

int is_prime(struct sieve_t *sv, unsigned n) {
    return !((sv->s[n / 8] >> n % 8) & 1);
}
void pn(struct sieve_t *sv, unsigned long long n) {	
	unsigned long long prime_no=1, prime = 2;		  
	while (prime_no != n )
	{		
		if(is_prime(sv, ++prime))
			prime_no++;
	}
	printf("%llu", prime);
}
int main() {
    int N;
   	unsigned long long n = 0;	
	int res;
    struct sieve_t sv;
    sv.n = 1000;
    sv.s = calloc((1000 + 1) / 8,sizeof(char)); 
    fill_sieve(&sv);

	res = scanf("%llu", &n);
    assert(res == 1);
	pn(&sv, n);

    free(sv.s);
    return 0;
}
