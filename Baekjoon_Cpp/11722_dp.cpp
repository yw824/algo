#include <iostream>
using namespace std ;

int* w ; 
int* dp ; 
int n ; 
int ans ;

void Load()
{
	cin >> n ; 
	w = new int[ n ] ; 
	dp = new int[ n ]{ 0 } ; 

	for( int i = 0 ; i < n ; ++i )
		cin >> w[ i ] ; 

	ans = 0 ; 
}

void DP()
{
	for( int i = 0 ; i < n ; ++i )
	{
		dp[ i ] += 1 ; 
		for( int j = i + 1 ; j < n ; ++j )
		{
			if( w[ i ] > w[ j ] )
				dp[ j ] = max( dp[ j ] , dp[ i ] ) ;
		}
	}

	for( int i = 0 ; i < n ; ++i )
		if( ans < dp[ i ] )
			ans = dp[ i ] ; 
}

void ShowData()
{
	for( int i = 0 ; i < n ; ++i )
		cout << dp[ i ] << " " ;
	cout << "\n" ; 
}

int main( void )
{
	Load() ; 
	DP() ; 
	// ShowData() ; 
	cout << ans << "\n" ; 
}