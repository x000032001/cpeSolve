/*
 * https://hackpad.com/UVa-Q10055-x2IaLDoHONq
 */

#include <cstdio>
#include <cassert>

typedef long long int lint;

lint abs( lint n );
lint solve( lint a , lint b );

/* SOLVE START */
lint abs( lint n )
{
	return n>=0 ? n : -n ;
}

lint solve( lint a , lint b )
{
	return abs(a-b);
}


/* SOLVE END */

/* TEST START */
void testAbs()
{
	lint A = (1L << 40) -1;
	assert( abs( A) == A );
	assert( abs(-A) == A );
}

void testSolve()
{
	assert( solve(10 ,12) == 2 );
	assert( solve(14 ,10) == 4 );
	assert( solve(100 ,200) == 100 );
}
/* TEST END */

int main()
{
#ifndef ONLINE_JUDGE
	testAbs();
	testSolve();
#endif

	lint a,b;
	while( EOF != scanf(" %lld %lld" ,&a ,&b ) )
		printf("%lld\n" ,solve(a ,b) );

	return 0;
}
