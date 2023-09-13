#include <iostream>
#include <string>
using namespace std ; 

int main( void )
{
	int len ; 
	string str ; 
	cin >> str ; 

	len = ( int )str.length() ; 

	long long ans ;

	if( str[ 0 ] == 'c' )
		ans = 26 ; 
	else if( str[ 0 ] == 'd' )
		ans = 10 ; 

	for( int i = 1 ; i < len ; ++i )
	{
		if( str[ i ] == 'c' ) // c
		{
			if( str[ i - 1 ] == str[ i ] ) // cc
			{
				ans *= 25 ; 
				continue ; 
			}
			ans *= 26 ; 
			continue ; 
		}
		if( str[ i ] == 'd' ) // d
		{
			if( str[ i - 1 ] == str[ i ] ) // dd
			{
				ans *= 9 ; 
				continue ; 
			}
			// cd
			ans *= 10 ; 
		}
	}

	cout << ans << "\n" ; 
}