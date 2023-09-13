#include <iostream>
#include <string>
using namespace std ;

int main( void )
{
	string* str ; 
	int n ; 
	cin >> n ; 

	str = new string[ n ] ; 
	int i , j , len ; 
	for( i = 0 ; i < n ; ++i )
	{
		cin >> str[ i ] ;
		len = ( int )str[ i ].length() ; 
		for( j = 0 ; j < len ; ++j )
			str[ i ][ j ] = ( str[ i ][ j ] + 1 ) % 'A' + 'A' ; 
	}

	for( i = 0 ; i < n ; ++i )
	{
		cout << "String #" << i + 1 << "\n" ; 
		len = str[ i ].length() ; 
		for( j = 0 ; j < len ; ++j )
			printf( "%c" , str[ i ][ j ] ) ;
		cout << "\n" ; 

		if( i < n - 1 )
			cout << "\n" ; 
	}

}