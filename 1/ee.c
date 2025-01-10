#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



long long eu_mod(long long x, long long y)
{
	long long r;
	r = x % y;

	if (r < 0)
	{		
		r += abs(y);
		return r;
	}

	return r;
}
void extended_e(long long a, 
                       long long b) {
	long long d, utmp, uold = 1, u = 0, vtmp, vold = 0, v = 1, q, r;
	if (abs(b) > abs(a))
	{
    a = b^a;
 		b = a^b;
    a = b^a;
	}

	while(b != 0)
	{
		q = a / b;
		r = abs(a)-abs(q*b); //eu_mod(a , b); 
		printf("abs(%lld)-abs(%lld * %lld) = %lld == eu_mod(a,b)=%lld\n",a,q,b, r, eu_mod(a,b) );
		a = b; 
		b = r;
		utmp = u; 
		u =  uold - q*u; 
		uold = utmp;
		vtmp = v; 
		v = vold - q*v; 
		vold = vtmp; 
	}
	d=a; u = uold; v = vold;
	assert(d == a*u + b*v);
	//if(b != 0)
		//v =  (d - a*u)/b;
  printf("%lld %lld %lld", u, v, d);
}


int main() {
	long long x = 0, y = 0;  
	
	int res;
  res = scanf("%lld %lld", &x, &y);
	assert(res == 2);
	
  extended_e(x, y);
  
	return 0;
}

