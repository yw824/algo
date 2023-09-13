#include <iostream>
#include <string>
using namespace std ;

bool status ; 
int alp[ 26 ] ; 

void initialize()
{
	for( int i = 0 ; i < 26 ; ++i )
		alp[ i ] = 0 ; 
	status = false ; // false : 모두 포함 , true : 하나라도 사용되지 않았을 때  
}

void Check()
{
	for( int i = 0 ; i < 26 ; ++i )
	{
		if( alp[ i ] == 0 )
		{
			if( status == false )
			{
				status = true ; 
				cout << "missing " ; 
			}
			printf( "%c" , i + 'a' ) ;
		}
	}
	
	if( status == false )
		cout << "pangram" ;
	cout << "\n" ;  
}

int main( void )
{
	int n ; 
	cin >> n ;
	getchar() ; 

	string str ;
	int len , i ;   
	while( n-- )
	{
		initialize() ;
		getline( cin , str ) ;
		// cout << str << " , " ; 

		// 대문자는 소문자 변환 필요 

		len = ( int )str.length() ; 
		for( i = 0 ; i < len ; ++i )
		{
			if( ( str[ i ] < 'a' || str[ i ] > 'z' ) && ( str[ i ] < 'A' || str[ i ] > 'Z' ) )
				continue ; 
			if( str[ i ] >= 'A' && str[ i ] <= 'Z' ) // 대문자이면 
			{
				alp[ str[ i ] - 'A' ] += 1 ; 
				continue ; 
			}
			alp[ str[ i ] - 'a' ] += 1 ; 
		}

		Check() ; 
	}
}