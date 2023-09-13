#include <iostream>
#include <string>
using namespace std ;

int main( void )
{
	string str ; 
	cin >> str ;
	// cout << 97-65 << "\n" ; // 32

	
	for( int i = 0 ; i < str.length() ; i++ )
	{
		if( str[ i ] >= 65 && str[ i ] <= 90 )
			str[ i ] += 32 ; 
		else if( str[ i ] >= 97 && str[ i ] <= 122 )
			str[ i ] -= 32 ; 
	}
	cout << str << "\n" ; 
	
}