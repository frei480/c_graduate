#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* allocate(unsigned long long size)
{
	int *arr = calloc(size, sizeof(int));
	if(arr)
	{
		for(int i=0;i< size;i++)
			arr[i] = 1;			
	}
	else {
	abort();
	}
	return arr; 
}

void pn(unsigned long long n)
{
	int *arr = allocate(n);
	unsigned i, j;
	int count = 0;		  
	for(i=2; i*i < n;i++)	
		if (arr[i])
			for(j = i*i;j < n;j += i)
				arr[j] = 0;			

	for(i=2; i < n; ++i)
		count += arr[i];

	printf("%d", count);
	free(arr);
}

int main() {
	unsigned long long n = 0;	
	int res;
  	res = scanf("%llu", &n);
  	assert(res == 1);
   	pn(n+1);
  	return 0;
}

