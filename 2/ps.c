#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
  int n;
  char *s;
};
char* allocate(int size)
{
	char *arr = calloc(size, sizeof(char));
	if(arr)	{ }
	else {	abort();	}
	return arr; 
}
int is_prime(int n){
	int i;
    if (n < 2) return 0;
	for(int j = 2; j*j <= n; ++j)
	{	
		if ((n%j) == 0)
		 return 0;
	}
	return 1;
}
void fill_sieve(struct sieve_t *sv)
{
    int i = 2, j;    
    while(i*i < sv->n){        
        j = i * i;            
        if(sv->s[i]){            
            ++i;
            continue;
        }
        while(j < sv->n){
            sv->s[j] = 1;
            j+=i;
        }
        ++i;        
    }
}

int nth_prime(struct sieve_t *sv, int N)
{
    int prime_no=1, prime = 2;		  
	while (prime_no != N)
	{		
		if(!sv->s[++prime])
			prime_no++;
	}	
    return prime;
}
int pn(int n) {	
	int prime_no=1, prime = 2;		  
	while (prime_no != n )
	{		
		if(is_prime(++prime))
			prime_no++;
	}	
    return prime;
}
int main() {
	struct sieve_t sv;
    int n = 0;
    int quantuty;
	int res;
    res = scanf("%d", &n);
    assert(res == 1);

    quantuty = pn(n)+1;
    sv.n = quantuty;
    sv.s=allocate(quantuty);

    fill_sieve(&sv);

    printf("%d\n",nth_prime(&sv, n));
    
   return 0;
}