#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 49

void fill_array(unsigned long long * array)
{
  unsigned long long a = 0, b = 1, n = 2, tmp;

  for(n = 2; n < N; ++n)
  {
    tmp = b;
    b = (a+b);
    a = tmp;
		*(array+n) = b;
  }

}

void read_array(unsigned long long *array)
{
	for (int i = 0; i < N; i++)
		printf("%d - %llu\n",i, *(array+i));
}

int find_in(unsigned int x, unsigned long long *array)
{
	int i = 0;
	for (i = 0; i < N; i++)
		if( *(array+i) >= x )
		{
			break;
		}
	return i-1;

}
int main()
{
  unsigned long long fib_array[N]={0,1};
  unsigned long long x;
  unsigned long long num;
  int res, idx, max_idx ;
  res = scanf("%llu", &x);
  assert(res == 1);

	fill_array(fib_array);

	max_idx = find_in(x, fib_array);

	for(int i= max_idx; i >=0; i--)
	{
		printf("x=%llu\n", x);
		if(x-fib_array[i] >=0)
		{
			printf("1");
			--i;
		}
		else
			printf("0");

		x-=fib_array[i];
	}



// read_array(fib_array);
// printf("%llu %llu", fibm);
  return 0;
}


