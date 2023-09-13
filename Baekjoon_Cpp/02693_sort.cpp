#include <iostream>
#include <algorithm>
using namespace std ;

int main( void )
{
	int n ; 
	int* w ; 

	cin >> n ; 
	w = new int[ 10 ] ;
	while( n-- )
	{
		for( int i = 0 ; i < 10 ; ++i )
			cin >> w[ i ] ; 
		sort( w , w +  10 ) ; 
		cout << w[ 7 ] << "\n" ; 
	}
}