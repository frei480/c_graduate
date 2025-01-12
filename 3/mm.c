#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res, min=0, max=0;
    unsigned n = 0;
    res = scanf("%u", &n);
    if (n==0) {
        printf("0 0");
        return 0;
    }
    
    int* inp = calloc(n, sizeof(int));
    assert(inp);

    for(int i=0; i<n; i++)
    {
        res=scanf("%d", &inp[i]);
        assert(res == 1);
        if (i==0) {max=inp[0]; min = inp[0];}
        max = (inp[i] > max ) ? inp[i] : max;
        min = (inp[i] < min ) ? inp[i] : min;
    }
    printf("%d %d", min, max);
    free(inp);
    return 0;
}