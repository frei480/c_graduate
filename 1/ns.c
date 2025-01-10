#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_conv(unsigned int x, unsigned int y);

int main()
{
unsigned int x , y;
int res;
res = scanf("%u%u", &x,&y);

assert(res==2);

print_conv(x,y);
return 0;
}

void print_conv(unsigned int x, unsigned int y)
{	
	unsigned int num[32] = {0};
	int k = 0;
	while(x!=0)
	{		
		num[k] = x % y;
		x /= y;
		k++;
	}
	k--;
	while(k >= 0)
		printf("%u", num[k--]);	
}
