#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int majority_element(const int *parr, int len)
{
  int majority, count = 0;
  for (int i = 0; i < len; i++)
  {
    if (count)
    {
      count += (parr[i] == majority ? 1 : -1);
    }
    else
    {
      majority = parr[i];
      count = 1;
    }
  }
  count = 0;
  for (int i = 0; i < len; i++)  {
    if (parr[i] == majority) count++;
  } 
  return (count > len/2) ? majority : -1;
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