#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int mypow(int base, int exp){
    int result = 1;    
    while (exp > 0)
    {
        if ((exp % 2) == 1) result = (result*base);
        exp /=2;
        base = (base*base);
    }
    return result;
}
int is_prime(int n){	
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	return 1;
}

int lenght(int n){    
    int count = 0;
    while(n) {
        n/=10;
        count++;
    }
    return count;
}

int is_circular(int n){
    int len = lenght(n);
    int mod = 0;
    for(int i = len; i > 0; i--){
        mod = n % 10;
        mod = mod * mypow(10, len-1);
        n = n/10 + mod;
        if(!is_prime(n)) return 0;
    }
    return 1;
}

int main() {
	
    int n=0, N = 0, nearest=0;
    
	int res;
    res = scanf("%d", &N);
    assert(res == 1);

    for(int i=0; i < 1000000;i++){
        nearest = N + i;        
        if(is_circular(nearest)){ printf("%d", nearest); break;}
        nearest = N - i;
        if(is_circular(nearest)) { printf("%d", nearest); break;}
    }
    return 0;
}