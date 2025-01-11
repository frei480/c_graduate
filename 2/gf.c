/*
n2 + n + 41, открытая Эйлером, генерирует для 0 <= n <= 39

n2 + an + b, в предположеннии, что |a| < N и |b| < N
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){	
    if (n == 2 || n == 3) return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	for(int j = 5; j*j <= n; j += 6)
		if (( (n % j) == 0) || ((n % (j+2))==0))
		    return 0;
	return 1;
}
int main() {
	
    int n=0, N = 0;
    int a, b, digit, max_len = 0;
	int res;
    res = scanf("%d", &N);
    assert(res == 1);
    for(int count_a=-N+1; count_a < N; ++count_a){
        for(int count_b=-N+1; count_b < N; ++count_b){
            n=0;
            while(1){
                digit = n*n + count_a*n + count_b;   
                if (digit <=0 || !is_prime(digit)) break;
                n++;
            }
            if (n > max_len){
                a = count_a;
                b = count_b;
                max_len = n;
            }
        }
    }
    
    printf("%d %d %d",a,b,max_len);
    
   return 0;
}