#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res, chunk, offset, change;
    unsigned n = 0;
    res = scanf("%u", &n);
    int* inp = calloc(n, sizeof(int));
    assert(inp);
    for(int i=0; i<n; i++)
    {
        res=scanf("%d", &inp[i]);
        assert(res == 1);
    }
    
    res = scanf("%d", &change);
    assert(res == 1);

    chunk = change / 8;
    offset = change % 8;  

    inp[chunk] = inp[chunk] ^ (1 << offset);

    for(int i=0; i<n; i++)
        printf("%d ",inp[i]);        
    
    return 0;
}