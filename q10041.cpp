/*
 * https://hackpad.com/UVa-Q10041-g0kdUs0MGof
 */

#include <stdio.h>
#include <assert.h>

void swap( int &a , int &b ); // not necessary
void sort( int array[] ,int size );
int getMedian( int array[] ,int size );
int abs( int n );
int solve( int array[] ,int size );

/* SOLVE START */
void swap( int &a , int &b )
{
	int temp = a;
	a = b;
	b = temp;
}

void sort( int array[] ,int size )
{
	for( int i = 0 ; i < size-1 ; ++i )
		for( int j = i+1 ; j < size ; ++j )
			if( array[i] > array[j] )
				swap( array[i] , array[j] );
}

int getMedian( int array[] ,int size )
{
	if( size % 2 == 1 )
		return array[size/2];
	else
		return (array[size/2]+array[size/2-1])/2;
}

int abs( int n )
{
	if( n >= 0 ) return  n;
	else		return -n;
}

int solve( int array[] ,int size )
{
	sort( array ,size );
	int med = getMedian( array ,size );

	int sum = 0;
	for( int i = 0 ; i < size ; ++i )
		sum += abs(array[i]-med);

	return sum;
}

/* SOLVE END */

/* TEST FUNC START */
void testSwap()
{
	int sA = 3 , sB = 5;
	swap( sA , sB );
	assert( sA == 5 && "swap error" );
	assert( sB == 3 && "swap error" );

	// you can add this , but I think that "no news is good news".
	//puts("swap successed"); 
}

void testSort()
{
	int before[] = {9 ,8 ,7 ,5 ,5};
	int after[]  = {5 ,5 ,7 ,8 ,9};
	sort( before , 5 );
	for( int i = 0 ; i < 5 ; ++i )
		assert( before[i] == after[i] && "sort error" );
}

void testAbs()
{
	assert( abs(3) == 3 );
	assert( abs(-4) == 4 );
}

void testGetMedian()
{
	int testOdd[] = {0 ,6 ,10};
	int testEven[] = {1 ,4 ,6 ,10};

	assert( getMedian( testOdd ,3 ) == 6 );
	assert( getMedian( testEven ,4 ) == 5 );	
}

void testSolver()
{
	int probA[] = {2 ,4};
	int probB[] = {2 ,4 ,6};
	int probC[] = {2 ,1 ,999 ,5};

	assert( solve(probA ,2) == 2 && "solve error" );
	assert( solve(probB ,3) == 4 && "solve error" );
	assert( solve(probC ,4) == 1001 && "solve error" );
}

/* TEST FUNC END */


int main()
{
#ifndef ONLINE_JUDGE
	testSwap();
	testSort();
	testAbs();
	testGetMedian();
	testSolver();
#endif

	int totalCaseNum = 0;
	scanf(" %d" , &totalCaseNum );

	for( int z = 0 ; z < totalCaseNum ; ++z )
	{
		int familyNum = 0;
		scanf(" %d" , &familyNum );

		int arr[500] = {};
		for( int i = 0 ; i < familyNum ; ++i )
			scanf(" %d" , &arr[i] );

		printf("%d\n" , solve(arr ,familyNum) );
	}	
	
	

	return 0;
}

