#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll eu_mod(ll x, ll y){
	ll r;
	r = x % y;
	if (r < 0)	{		
		r += abs(y);		
	}
	return r;
}

ll extended_e(ll a, ll b, ll* x, ll* y) {
	ll x0 = 1, x1 = 0, y0=0, y1 = 1, q, r, tmp;    	
	while(b)	{
		q = a / b;
		if(q<0) q-=1;
		r = eu_mod(a, b);
		*x = x0 - q * x1;
		//for next step
		a = b; b = r; 
		x0 = x1; x1 = *x;		
	}
	*x=x0;
	return a;	
}

int main() {
	ll a = 0, b = 0, x = 0, y = 0, gcd = 0;  	
	int res;
	
  	res = scanf("%lld %lld", &a, &b);
	assert(res == 2);
		
	gcd = extended_e(a, b, &x, &y);
	y = (gcd - x * a) / b;
	printf("%lld %lld %lld", x, y, gcd);
	return 0;
}

