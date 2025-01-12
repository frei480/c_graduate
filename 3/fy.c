#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

int main()
{
    int res, min=0, max=0;
    unsigned n = 0;
    res = scanf("%u", &n);
    if (n==0) {
        printf("0 0");
        return 0;
    }
    
    // int* inp = calloc(n, sizeof(int));
    // assert(inp);

    for(int i=0; i < 5; i++)
    {
        // res=scanf("%d", &inp[i]);
        // assert(res == 1);
        myrand();
        printf("%d", myrand()%5);

    }
   
    return 0;
}