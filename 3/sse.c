#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *create_array(int size)
{
    int res;
    int *array = calloc(size, sizeof(int));
    assert(array);

    for (int i = 0; i < size; i++)
    {
        res = scanf("%d", &array[i]);
        assert(res == 1);
    }
    return array;
}

void print_array(int *inp, unsigned int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", inp[i]);
}

void selsort(int *inp, unsigned int size, unsigned pos){    
    int minindex=pos, i = pos+1;
    for (; i < size; i++)
        if(inp[i] < inp[minindex])
            minindex = i;
    if (minindex != pos)
    {
        inp[pos] ^= inp[minindex];
        inp[minindex] ^= inp[pos];
        inp[pos] ^= inp[minindex];            
    }              
}

int main()
{
    unsigned res, pos, size = 0;     
    int *inp;
    res = scanf("%u", &size);
    assert(res == 1);
    assert(size > 0);
    inp = create_array(size);
    res = scanf("%u", &pos);
    assert(res == 1);    
    selsort(inp, size, pos);    
    print_array(inp, size);
    free(inp);
}
