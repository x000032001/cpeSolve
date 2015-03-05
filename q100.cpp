/*
 * https://hackpad.com/UVa-Q100-MatnOUyIuXE
 */

#include <cstdio>
#include <cassert>

/* SOLVE */
int func( long long int n )
{
	int count = 1;
	while( n != 1 )
	{
		count++;
		if( n%2==0 )
			n /= 2;
		else
			n = n*3+1;

		assert( n>0 );
	}

	return count;
}

int solve( int a ,int b )
{
	if( a > b )
	{
		int t = a;
		a = b;
		b = t;
	}

	int max = 0;
	for( int i = a ; i <= b ; ++i )
	{
		int ret = func(i);
		if( ret > max )	max = ret;
	}

	return max;
}
/* SOLVE */

/* TEST */
void testFunc()
{
	assert( func(22)==16 );
}

void testSolve()
{
	assert( solve(1,10)==20 );
	assert( solve(10,1)==20 );
	assert( solve(100,200)==125 );
	assert( solve(201,210)==89 );
	assert( solve(900,1000)==174 );
}
/* TEST */

int main()
{
#ifndef ONLINE_JUDGE
	testFunc();
	testSolve();
#endif

	int a,b;
	while( scanf(" %d %d" ,&a ,&b ) != EOF )
		printf("%d %d %d\n" , a , b , solve(a,b) );

	return 0;
}
