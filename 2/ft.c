#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long ull;

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

int main(){
    ull P;
    int res, iterations=1000;
    res = scanf("%llu", &P);
    assert(res==1);
    res=fermat_test(P, iterations);
    printf("%d", res);
}