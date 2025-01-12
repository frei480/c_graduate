#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int majority_element(const int *parr, int len)
{
    int max = parr[0];
    int * buckets;
    for (int i = 0; i < len; i++){
        max = (parr[i] > max )? parr[i]: max;
    }
    max++;
    buckets = calloc(max, sizeof(int));
    for (int i = 0; i < len; i++)
        buckets[parr[i]]++;

    for(int i = 0; i < max; i++)
        if (buckets[i] >= len/2)
            return i;
    return -1;
}

int main() {
  int res, n, i, answ;
  int *arr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  arr = calloc(n, sizeof(int));
  for (i = 0; i < n; ++i) {
    res = scanf("%d", arr + i);
    assert(res == 1);
  }

  answ = majority_element(arr, n);

  printf("%d\n", answ);

  free(arr);
  return 0;
}