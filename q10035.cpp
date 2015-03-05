/*
 * https://hackpad.com/UVa-Q10035-1Mjl2h8gGza
 */

#include <cstdio>
#include <cassert>

#define SIZE 13
typedef long long int lint;

int solve( int a[SIZE] ,int b[SIZE] );
void lintToArray( lint n ,int arr[SIZE] );

/* SOLVE */
int solve( lint ia ,lint ib )
{
	int a[SIZE] = {} ,b[SIZE] = {};
	lintToArray( ia , a );
	lintToArray( ib , b );

	int carryTimes = 0;
	int carryBit = 0;

	for( int i = 0 ; i < SIZE ; ++i )
	{
		int c = a[i] + b[i] + carryBit;
		if( c >= 10 )
		{
			carryTimes++;
			carryBit = 1;
		}
		else
			carryBit = 0;
	}

	return carryTimes;
}

void lintToArray( lint n ,int arr[SIZE] )
{
	int index = 0;
	while( n != 0 )
	{
		arr[index] = n%10;
		n /= 10;
		index++;
	}

	for( ; index < SIZE ; ++index )
		arr[index] = 0;
}

/* SOLVE */

/* TEST */

void testLintToArray()
{
	lint n = 1234567890;
	int arr[SIZE] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int conv[SIZE] = {};

	lintToArray( n ,conv );
	for( int i = 0 ; i < SIZE ; ++i )
		assert( conv[i] == arr[i] );
}

void testSolve()
{
	assert( solve(123,456)==0 );
	assert( solve(555,555)==3 );
	assert( solve(123,594)==1 );	
}

/* TEST */

int main()
{
#ifndef ONLINE_JUDGE
	testLintToArray();
	testSolve();
#endif

	lint a ,b;

	//while( scanf(" %lld %lld" ,&a ,&b ) , a!=0 && b!=0 )
	while( scanf(" %lld %lld" ,&a ,&b ) )
	{
		if( a==0 && b==0 ) break;
		
		int ret = solve(a,b);

		switch(ret)
		{
			case 0:
				puts("No carry operation.");
				break;
			case 1:
				puts("1 carry operation.");
				break;
			default:
				printf("%d carry operations.\n",ret);
				break;
		}
	}

	return 0;
}
