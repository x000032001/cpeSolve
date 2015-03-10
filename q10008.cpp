#include <cstdio>
#include <cassert>

int alphaCount[26] = {};
int alphaUsed[26] = {};

char MtoLower( char c )
{
	if( 'A'<=c && c<='Z' )
		return c+'a'-'A';
	else
		return c;
}

int MisAlpha( char c )
{
	if( 'a'<=c&&c<='z' )
		return 1;
	if( 'A'<=c&&c<='Z' )
		return 1;
	return 0;
}

int findMax()
{
	int max=0;
	int index=-1;

	for( int i = 0 ; i < 26 ; ++i )
		if( alphaUsed[i]==0 && max < alphaCount[i] )
		{
			index = i;
			max = alphaCount[i];
		}

	return index;
}

int main()
{
	int lineN;
	scanf(" %d",&lineN);
	getchar();
	while(1)
	{
		char line[2000] = {};
		if( !fgets(line,2000,stdin) )
			break;
		for( int i = 0 ; line[i] ; ++i )
			if( MisAlpha(line[i]) )
			{
				char c = MtoLower(line[i]);
				alphaCount[c-'a']++;
			}
	}

	while(1)
	{
		int ret = findMax();
		if( ret == -1 )
			break;
		for( int i = 0 ; i < 26 ; ++i )
		{
			if( alphaCount[ret]==alphaCount[i] )
			{
				alphaUsed[i] = 1;
				printf("%c %d\n",i+'A',alphaCount[i]);
			}
		}

	}
	
	return 0;
}
