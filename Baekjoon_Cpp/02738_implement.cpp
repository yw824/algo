#include <iostream>
using namespace std ;

int n ; 
int m ; 
int** w ; 

void LoadMatrix()
{
	cin >> n >> m ; 
	w = new int*[ n ] ; 
	for( int i = 0 ; i < n ; ++i )
	{
		w[ i ] = new int[ m ]{ 0 } ; 
		for( int j = 0 ; j < m ; ++j )
			cin >> w[ i ][ j ] ;
	}
	int temp ; 
	for( int i = 0 ; i < n ; ++i )
		for( int j = 0 ; j < m ; ++j )
		{
			cin >> temp ; 
			w[ i ][ j ] += temp ; 
		}
}

void ShowData()
{
	for( int i = 0 ; i < n ; ++i )
	{
		for( int j = 0 ; j < m ; ++j )
			cout << w[ i ][ j ] << " " ;
		cout << "\n" ;
	}
}

int main( void )
{
	LoadMatrix() ; 
	ShowData() ; 
}