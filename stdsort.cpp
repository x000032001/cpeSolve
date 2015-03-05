#include <cstdio>
#include <algorithm> // for std::sort
#include <cassert>

using std::sort; //must have this statement

int main()
{
	int A[] = {3, 4, 8, 7, 1};
	int size = 5;
	sort( A , A+size );

	int B[] = {1, 3, 4, 7, 8};
	for( int i = 0 ; i < size ; ++i )
		assert( A[i] == B[i] && "sort test" );

	puts("sort done");

	return 0;
}
