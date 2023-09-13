#include <iostream>
using namespace std ; 

int n ; 
int* w ;
int* d ; 

void Load()
{
	cin >> n ; 
	w = new int[ n ] ; 
	d = new int[ n ] ;

	for( int i = 0 ; i < n ; ++i )
	{
		cin >> w[ i ] ; 
		d[ i ] = 0 ; 
	}

}

void ShowData( int index )
{
	cout << index << " : " ; 
	for( int i = 0 ; i < n ; ++i )
		cout << d[ i ] << " " ; 
	cout << "\n" ; 
}

int DP()
{
	for( int i = 0 ; i < n ; ++i )
	{
		d[ i ] += 1 ; 
		for( int j = i + 1 ; j < n ; ++j )
			if( w[ j ] > w[ i ] )
				d[ j ] = max( d[ i ] , d[ j ] ) ;
		// ShowData( i ) ;
	}

	int ans = 0 ; 
	for( int i = 0 ; i < n ; ++i )
		if( ans < d[ i ] )
			ans = d[ i ] ; 
	return ans ; 
}

int main( void )
{
	Load() ; 
	cout << DP() << "\n" ;
}