#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res, n, low=-1, high = 0;
    res = scanf("%d", &n);
    assert(res == 1);
    if (n==0){
        printf("NO");
        return 0;
    }
    
    if ((n&1)) low = 0;
    
    for(int i=0; i<32; i++)
    {
        if (low == -1 && ( (n >> i) & 1) ) 
            low = i; 
        if ((n >> i) & 1)
            high = i;
    }
    printf("%d %d",high, low);
    return 0;
}