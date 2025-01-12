#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned long long int ull;
// ull BIG = 1152921504606846976;
ull BIG = 1746860020068409;

int is_prime(ull n){
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	return 1;
}
ull mod_exp(ull base, ull exp, ull mod){
    ull result=1;
    base = base % mod;
    while (exp > 0)
    {
        if ((exp % 2) == 1) result = (result*base) % mod;
        exp /=2;
        base = (base*base) % mod;
    }
    return result;
}
int fermat_test(ull P, int iter){
    int res=1;
    if (P < 2) return 0;
    if ((P != 2) && (P % 2==0)) return 0;
    
    for(int i=0; i < iter; i++) {
        srand(time(0));
        ull r = 2 + rand() % (P-3);
        
        if(mod_exp(r, P-1, P) != 1) res = 0;        
    }
    return res;
}
ull fib_like(ull k, ull n)
{
    ull a=1ull, b=1ull, tmp, P=0ull;
    for(ull i=10ull; i<BIG; i++){
        tmp=b;
        b=k*a+n*b;
        a=tmp;        
        if(fermat_test(b, 10)) {P=a; printf("working\n");}
        }
    return P;
}

int main()
{
    ull P=0, k, n;
    int res;
    res = scanf("%llu%llu",&k, &n);
    assert(res==2);
    P=fib_like(k, n);
    printf("%llu", P);
    return 0;
}