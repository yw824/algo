#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

int n ; // row
int m ; // col
int** w ; // current status
int** d ; // initial array
int ans ; // answer
vector< pair< int , int > > v ; 

void LoadMatrix()
{
	cin >> n >> m ; 

	w = new int*[ n + 2 ] ;
	d = new int*[ n + 2 ] ; 

	for( int i = 0 ; i <= n + 1 ; ++i )
	{
		w[ i ] = new int[ m + 2 ]{ 0 } ;
		d[ i ] = new int[ m + 2 ]{ 0 } ; 

		for( int j = 0 ; j <= m + 1 ; ++j )
			if( !i || i == n + 1 || !j || j == m + 1 )
				w[ i ][ j ] = 1 ; 
			else
				cin >> w[ i ][ j ] ; 
	} 
	ans = 0 ; 
}

// find the safe area after spreading the virus
int findSafeArea()
{
	int count = 0 ; 
	for( int i = 1 ; i <= n ; ++i )
		for( int j = 1 ; j <= m ; ++j )
			if( !d[ i ][ j ] )
				++count ; 

	return count ; 
}

// Spread the virus
void Search( int x , int y )
{
	d[ x ][ y ] = -1 ; 
	if( !d[ x - 1 ][ y ] )
		Search( x - 1 , y ) ;
	if( !d[ x + 1 ][ y ] )
		Search( x + 1 , y ) ;
	if( !d[ x ][ y - 1 ] )
		Search( x , y - 1 ) ;
	if( !d[ x  ][ y + 1 ] )
		Search( x , y + 1 ) ;
}

void Check()
{
	int i , j ; 
	// copy w to d
	for( i = 0 ; i <= n + 1 ; ++i )
		for( int j = 0 ; j <= m + 1 ; ++j )
			d[ i ][ j ] = w[ i ][ j ] ;

	// Spread the virus
	for( i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; ++j )
			if( d[ i ][ j ] == 2 )
			{
				Search( i , j ) ; 
			}

	// find the safe area after spreading the virus
	int count = findSafeArea() ; 
	if( ans < count )
		ans = count ; 
}

void Next_Permutations( int cnt ) // set 3 walls
{
	// set all 3 walls : check the safe area
	if( cnt == 3 )
	{
		Check() ; 
		return ; 
	}

	// get current status : last wall set
	int x , y ;
	if( !v.size() ) 
	{ 
		x = 1 ; y = 0 ; 
	}
	else 
	{
		x = v.back().first ;
		y = v.back().second ; 
	}


	
	// set new wall
	for( int i = x ; i <= n ; ++i )
		for( int j = 1 ; j <= m ; ++j )
		{
			if( i == x && j <= y )
				continue ;

			if( !w[ i ][ j ] )
			{
				v.push_back( pair< int , int >( i , j ) ) ;  
				w[ i ][ j ] = 1 ; 
				Next_Permutations( cnt + 1 ) ;
				v.pop_back() ; 
				w[ i ][ j ] = 0 ; 
			}

		}

}

void ShowData() // showdata for w
{
	for( int i = 0 ; i <= n + 1 ; ++i )
	{
		for( int j = 0 ; j <= m + 1 ; ++j )
			cout << w[ i ][ j ] << " " ;
		cout << "\n" ; 
	}
}

int main( void )
{
	LoadMatrix() ; 
	// ShowData() ; // input OK

	Next_Permutations( 0 ) ; 
	cout << ans << "\n" ; 
}