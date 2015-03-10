#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

struct countryCount {
	char name[75];
	int count;
} countrySet[2000];

int findCC( const char* str );

int CCtop = 0;

void newCC( const char* str )
{
	int index = findCC(str);
	if( index==-1 )
	{
		strcpy( countrySet[CCtop].name , str );
		if( countrySet[CCtop].name == NULL )
			exit(2);
		countrySet[CCtop].count++;
		CCtop++;
	}
	else
	{
		countrySet[index].count++;
	}

}

void freeCC()
{
	for( int i = 0 ; i < CCtop ; ++i )
		free(countrySet[i].name);
}

int findCC( const char* str )
{
	for( int i = 0 ; i < CCtop ; ++i )
		if( strcmp(str,countrySet[i].name)==0 )
			return i;

	return -1;	
}

void printCC()
{
	for( int i = 0 ; i < CCtop ; ++i )
		printf("%s %d\n" , countrySet[i].name , countrySet[i].count );
}

void sortCC()
{
	for( int i = 0 ; i < CCtop-1 ; ++i )
		for( int j = i+1 ; j < CCtop ; ++j )
			if( strcmp(countrySet[i].name,countrySet[j].name) > 0 )
			{
				char tmp[75] = {};
				strcpy( tmp , countrySet[i].name );
				strcpy( countrySet[i].name , countrySet[j].name );
				strcpy( countrySet[j].name , tmp);

				int val = countrySet[i].count;
				countrySet[i].count = countrySet[j].count;
				countrySet[j].count = val;
			}
}

void testCC()
{
	newCC("Spain");
	newCC("England");
	newCC("Spain");	

	sortCC();
	printCC();

	freeCC();
}

int main()
{
//	testCC();

	int cases;
	scanf("%d",&cases);
	getchar();
	for( int i = 0 ; i < cases ; ++i )
	{
		char line[75]={};
		fgets(line,75,stdin);
		char country[75]={};
		sscanf(line,"%s",country);
		newCC(country);
	}

	sortCC();
	printCC();
	//freeCC();
	return 0;
}
