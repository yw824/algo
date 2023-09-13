#include <iostream>
using namespace std ;

int n ; // 가로 길이
int m ; // 세로 길이
int** w ; // 배열
int k ; // 음식물 쓰레기 개수
int ans ; 
int count ; // count while DFS

void LoadMatrix()
{
	cin >> n >> m >> k ; 

	w = new int*[ n + 2 ] ; 
	for( int i = 0 ; i <= n + 1 ; i++ )
		w[ i ] = new int[ m + 2 ]{ 0 } ; 

	int x , y ; 
	for( int i = 0 ; i < k ; i++ )
	{
		cin >> x >> y ; 
		w[ x ][ y ] = -1 ;  
	}

	ans = 0 ; 
	count = 0 ; 
}

void DFS( int i , int j )
{
	w[ i ][ j ] = ++count ; 
	if( count > ans ) ans = count ;

	if( w[ i - 1 ][ j ] < 0 )
		DFS( i - 1 , j ) ;
	if( w[ i + 1 ][ j ] < 0 )
		DFS( i + 1 , j ) ;
	if( w[ i ][ j - 1 ] < 0 )
		DFS( i , j - 1 ) ;
	if( w[ i ][ j + 1 ] < 0 )
		DFS( i , j + 1 ) ;
}

void ShowData()
{
	for( int i = 0 ; i <= n + 1 ; i++ )
	{
		for( int j = 0 ; j <= m + 1 ; j++ )
			cout << w[ i ][ j ] << " " ; 
		cout << "\n" ; 
	}
}

int main( void )
{
	LoadMatrix() ; 
	// ShowData() ; 

	for( int i = 1 ; i <= n + 1 ; i++ )
		for( int j = 1 ; j <= m + 1 ; j++ )
			if( w[ i ][ j ] < 0 )
			{
				DFS( i , j ) ;
				count = 0 ; 
			}

	// ShowData() ; 

	cout << ans << "\n" ; 
}