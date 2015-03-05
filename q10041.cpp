/*

https://hackpad.com/UVa-Q10041-g0kdUs0MGof

Q10041: Vito's family

世界聞名的黑社會老大Vito Deadstone要搬到紐約來了。
在那裡他有一個大家族，並且他們都住在Lamafia大道上。
因為Vito時常要拜訪所有的親戚，他想要找一間離他們最近的房子，也就是說他希望從他的家到所有的親戚的家的距離的和為最小。

他恐嚇你寫一個程式來幫助幫助他解決這個問題。

Input

輸入的第一列有一個整數代表以下有多少組測試資料。

每組測試資料一列，第一個整數 r（0 < r < 500），代表他親戚的數目。
接下來的r個整數s1,s2,......sr為這些親戚房子的門牌號碼（0 < si <30000）。
注意：有些親戚的門牌號碼會相同。

Output

對每一組測試資料，輸出從他的新家到所有的親戚的家的距離的和為最小為多少。2個門牌號碼si、sj的距離為si-sj的絕對值。

http://www3.tcgs.tc.edu.tw/~sagit/luckycat/q10041.htm

*/

#include <stdio.h>
#include <assert.h>

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

