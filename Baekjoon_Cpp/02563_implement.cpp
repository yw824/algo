#include <iostream>
using namespace std ; 

bool** w ;

void Color( int x , int y ) 
{
	int fromX = x ; 
	int toX = min( x + 9 , 100 ) ; // 0부터 9까지 10개 
	int fromY = y ; 
	int toY = min( y + 9 , 100 ) ;

	for( int i = fromX ; i <= toX ; ++i )
		for( int j = fromY ; j <= toY ; ++j )
			w[ i ][ j ] = true ;
} 

void LoadMatrix()
{

	w = new bool*[ 101 ] ; 
	for( int i = 0 ; i <= 100 ; ++i )
		w[ i ] = new bool[ 101 ]{ false } ;

	int n, x , y ; 
	cin >> n ;

	while( n-- )
	{
		cin >> x >> y ; 
		Color( x , y ) ;
	}
}

int getTotal()
{
	int ans = 0 ; 
	for( int i = 1 ; i <= 100 ; ++i )
		for( int j = 1 ; j <= 100 ; ++j )
			if( w[ i ][ j ] )
				ans += w[ i ][ j ] ;
	return ans ; 
}

void ShowData() 
{
	for( int i = 1 ; i <= 100 ; ++i )
	{
		for( int j = 1 ; j <= 100 ; ++j )
			cout << w[ i ][ j ] << " " ;
		cout << "\n" ;
	}
}

int main( void )
{
	LoadMatrix() ; 
	// ShowData() ; 
	cout << getTotal() << "\n" ; 
}