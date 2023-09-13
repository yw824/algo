#include <iostream>
using namespace std ;

int n ; 
int* w ; 
int* fward ; // forward
int* bward ; // backward
int ans ; 

void ShowData()
{
	for( int i = 0 ; i < n ; ++i )
		cout << fward[ i ] << " " ;
	cout << "\n" ; 
	for( int i = 0 ; i < n ; ++i )
		cout << bward[ i ] << " " ;
	cout << "\n" ; 
}

void Check() 
{
	int i , comp ; 
	for( i = 0 ; i < n ; ++i )
	{
		// 본인은 두번 더해졌으므로 한 번 빼야 함 
		comp = fward[ i ] + bward[ i ] - 1 ; 

		if( ans < comp )
			ans = comp ; 
	}

}

void DP()
{
	for( int i = 0 ; i < n ; ++i )
	{
		fward[ i ] += 1 ; 
		for( int j = i + 1 ; j < n ; ++j )
		{
			if( w[ j ] > w[ i ] && fward[ j ] < fward[ i ] )
				fward[ j ] = fward[ i ] ; 
		}
	}

	for( int i = n - 1 ; i >= 0 ; --i )
	{
		bward[ i ] += 1 ; 
		for( int j = i - 1 ; j >= 0 ; --j )
		{
			if( w[ j ] > w[ i ] && bward[ j ] < bward[ i ] )
				bward[ j ] = bward[ i ] ; 
		}
	}
}

void Load()
{
	cin >> n ; 
	w = new int[ n ] ; 
	fward = new int[ n ]{ 0 } ; 
	bward = new int[ n ]{ 0 } ;

	for( int i = 0 ; i < n ; ++i )
	{
		cin >> w[ i ] ;
	}
	ans = 0 ; 
}

int main( void )
{
	Load() ; 
	DP() ; 
	Check() ;
	// ShowData() ;

	cout << ans << "\n" ;  
}