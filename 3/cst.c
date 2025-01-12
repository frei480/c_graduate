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
int *bucketsort(int *inp, unsigned int size, int *max)
{
    *max = inp[0];
    int *buckets;
    for (int i = 0; i < size; i++)
        *max = (inp[i] > (*max)) ? inp[i] : (*max);
    (*max)++;
    buckets = calloc(*max, sizeof(int));
    for (int i = 0; i < size; i++)
        buckets[inp[i]] += 1;
    return buckets;
}
int main()
{
    int res;
    unsigned size = 0;
    int *inp, max;
    res = scanf("%u", &size);
    assert(res == 1);
    assert(size > 0);
    inp = create_array(size);
    int *out = bucketsort(inp, size, &max);
    print_array(out, max);
    free(inp);
}