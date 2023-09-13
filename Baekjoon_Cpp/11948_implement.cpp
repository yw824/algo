#include <iostream>
#include <algorithm>
using namespace std ;

int main( void )
{
	int sci[ 4 ] ; 
	int soc[ 2 ] ; 

	cin >> sci[ 0 ] >> sci[ 1 ] >> sci[ 2 ] >> sci[ 3 ] ; 
	cin >> soc[ 0 ] >> soc[ 1 ] ; 

	sort( sci , sci + 4 ) ;
	sort( soc , soc + 2 ) ;

	cout << ( sci[ 3 ] + sci[ 2 ] + sci[ 1 ] + soc[ 1 ] ) << "\n" ; 
}