#include <cstdio>
#include <cassert>
#include <cstring>

/* SOLVE */
int isZero(const char *arr)
{
	if( strlen(arr) == 1 && arr[0] == '0' )
		return 1;
	return 0;
}
int solve(const char* line)
{

	if( isZero(line) ) return -1;

	int A=0,B=0;

	for( int i = 0 ; line[i] != '\0' ; ++i )
		if( i % 2 == 0 )
			A += line[i]-'0';
		else
			B += line[i]-'0';
	
	int f = A-B;
	f = f >= 0 ? f : -f;	//abs
	printf("%d %d %d\n",f,A,B);

	if( f%11==0 )
		return 1;
	else
		return 0;
}

/* SOLVE */

/* TEST */

void testIsZero()
{
	assert( isZero("0") == 1 );
	assert( isZero("1") == 0 );
	assert( isZero("11") == 0 );
	assert( isZero("") == 0 );
}

void testSolve()
{
	assert( solve("112233")==1 );
	assert( solve("30800")==1 );
	assert( solve("2937")==1 );
	assert( solve("323455693")==1 );
	assert( solve("5038297")==1 );
	assert( solve("112234")==0 );
	assert( solve("0")==-1 );
}

/* TEST */


int main()
{
	//testIsZero();
	//testSolve();

	while(1)
	{
		char line[1004] = {};
		assert( NULL != fgets( line , 1004 , stdin ) );

		for( int i = 0 ; i < 1004 ; ++i )
			if( line[i]=='\n' ) line[i]='\0';

		int ret = solve(line);

		if( ret == -1 )
			break;
		if( ret == 1 )
			printf("%s is a multiple of 11.\n",line);
		if( ret == 0 )
			printf("%s is not a multiple of 11.\n",line);
	}

	return 0;
}
