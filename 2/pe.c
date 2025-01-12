#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
    int n;           
    unsigned char *s;
};

void set_prime(struct sieve_t *sv, unsigned n){
    int bytenum = n/8;
    int bitnum = n % 8;
    sv->s[bytenum] |= (1 << bitnum);
}

int is_prime(struct sieve_t *sv, unsigned n) {
    int bytenum = n/8;
    int bitnum = n % 8;
    int x = (sv->s[bytenum] >> bitnum) & 1;
    return (x==0)? 1 : 0;
}

void fill_sieve(struct sieve_t *sv) {
    int size=sv->n;
    size*=8;    
    for (unsigned i = 2; i * i <= size+1; i++) 
        if (is_prime(sv, i))  
            for (unsigned j = i * i; j <= size; j += i) 
                set_prime(sv, j);         
   
}

void pn(struct sieve_t *sv, unsigned long long n) {	
	unsigned prime_no=1, prime = 2;		  
	while (prime_no != n )
	{		
		if(is_prime(sv, ++prime))
			prime_no++;
	}
	printf("%u", prime);
}
int main() {
    int N;
   	unsigned long long n = 0;	
	int res;
    struct sieve_t sv;
    sv.n = 179424673/8+1;
    sv.s = (char*)calloc(sv.n ,sizeof(char)); 
    fill_sieve(&sv);

	res = scanf("%llu", &n);
    assert(res == 1);
	pn(&sv, n);

    free(sv.s);
    return 0;
}
