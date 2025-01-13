#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 49
typedef unsigned long long ull;
void fill_array(ull * array)
{
  ull a = 0, b = 1, n = 2, tmp;

  for(n = 2; n < N; ++n)
  {
    tmp = b;
    b = (a+b);
    a = tmp;
		*(array+n) = b;
  }

}

void read_array(ull *array)
{
	for (int i = 0; i < N; i++)
		printf("%d - %llu\n",i, *(array+i));
}

int find_in(unsigned int x, ull *array)
{
	int i = 0;
	for (i = 0; i < N; i++)
		if( array[i] > x )
		{
			break;
		}
	
	return i-1;

}
int main()
{
	ull fib_array[N]={0,1};
  	ull x, f;
  	ull num;
  	int res, idx, max_idx, is_add=0 ;
  	res = scanf("%llu", &x);
  	assert(res == 1);

	fill_array(fib_array);

	max_idx = find_in(x, fib_array);

	for(int i = max_idx; i > 1; i--)
	{		
		
		f = fib_array[i];
		
		if (f <= x)
		{
			if (is_add==0)
			{
				printf("1");
				is_add = 1; // флаг взяли число
				
			}
			else
			{
				printf("0");
				is_add = 1; // флаг не взяли число
			}
			x -= f;			
		}
		else
		{
			printf("0");
			is_add = 0;
		}
	
	}

  return 0;
		
	}





