#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull gcd(ull x, ull y){
    int q;
    while(y){
        q = x % y;
        x = y;
        y = q;
    }
    return x;
}
ull lcm(ull x, ull y){
    return x*y/gcd(x,y);
}
int main()
{
    ull res, n;

    res = scanf("%llu", &n);
    assert(res==1);
    res = 1;
    for(int i=2; i <= n; i++)
        res = lcm(res,i);
    printf("%llu", res);        
    
    return 0;
}