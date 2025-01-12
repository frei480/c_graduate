#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}
void swap(int *a, int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
int * create_array(int size){
    int res;
    int * array = calloc(size, sizeof(int));
    assert(array);

    for(int i=0; i < size; i++){
        res=scanf("%d", &array[i]);
        assert(res == 1);        
    }
    return array;
}
void print_array(unsigned int n, int *inp){
    for (int i = 0; i < n; i++)
        printf("%d ", inp[i]);    
}

int main()
{
    int res, min=0, max=0;
    unsigned n = 0;
    res = scanf("%u", &n);
    if (n==0) {
        printf("0");
        return 0;
    }
    
    int* inp = create_array(n);
    assert(inp);

    for(int i=n; i > 1; --i)
    {     
        swap(inp+(myrand()%i), inp+i-1 );        
    }
    print_array(n, inp);
    return 0;
}