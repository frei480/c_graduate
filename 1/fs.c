#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_conv(unsigned int x);

int main()
{
unsigned int x;
int res;
res = scanf("%u", &x);

assert(res==1);

print_conv(x);
return 0;
}

void print_conv(unsigned int x)
{		
	unsigned int i, num[11]= {0}, fact[11];
	unsigned int k = 0;	
	fact[0]=1;

	for(i = 1; i < 11; i++)
	{
		if(fact[i-1]*i <= x)
			{
				fact[i] = fact[i-1]*i;
				k = i;
			}
		else { break;}
	}

	for(i = k; i > 0; i--)
	{		
	  num[i] = x / fact[i];		
		x %= fact[i];
	}

	while(k > 0)		
		printf("%u.", num[k--]);	
}
