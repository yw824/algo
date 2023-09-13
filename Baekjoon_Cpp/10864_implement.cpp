#include <iostream>
using namespace std ;

int main( void )
{
	int* w ; 
	int n , m ; 
	cin >> n >> m ;

	w = new int[ n + 1 ]{ 0 } ; 
	int x , y ; 
	while( m-- )
	{
		cin >> x >> y ; 
		w[ x ] += 1 ; 
		w[ y ] += 1 ; 
	}

	for( int i = 1 ; i <= n ; ++i )
		cout << w[ i ] << "\n" ; 
}