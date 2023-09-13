#include <iostream>
#include <vector>
using namespace std ; 

int n ; 
int** w ; 
int ans ; 
vector< int > v ; 
int* count ; 

void LoadMatrix() 
{
	cin >> n ;

	w = new int*[ n ] ; 
	for( int i = 0 ; i < n ; ++i )
	{
		w[ i ] = new int[ n ]{ 0 } ;
		for( int j = 0 ; j < n ; ++j )
		{
			cin >> w[ i ][ j ] ;
			if( w[ i ][ j ] == 0 && i != j )
				w[ i ][ j ] = 1000000 ; 
		}
	}

	ans = n * 1000000 ; 

	count = new int[ n ]{ 0 } ;
	for( int i = 0 ; i < n ; ++i )
		count[ i ] = -1 ;
}

int getPoint( int point )
{
	for( int i = 0 ; i < n ; ++i )
		if( count[ i ] == point ) 
			return i ; 
	return - 1 ; 
}

void Check() // 1부터 n까지 , v.size() = n 
{
	int total = 0 ; 
	int point , next ; 
	for( int i = 0 ; i < v.size() ; ++i )
	{
		point = getPoint( v[ i ] ) ;
		next = getPoint( ( v[ i ] + 1 ) % n ) ; 

		if( point == -1 || next == -1 )
			return ; 

		total += w[ point ][ next ] ; 
		if( total > ans )
			return ; 
	}
	if( total < ans )
		ans = total ; 
}

void Next_Permutations( int cnt )
{
	if( v.size() == n )
	{
		Check() ; 
		return ; 
	}

	for( int i = 0 ; i < n ; ++i )
	{
		if( count[ i ] != -1 )
			continue ; 

		count[ i ] = v.size() ; // 0부터
		v.push_back( i ) ;
		Next_Permutations( cnt + 1 ) ;
		count[ i ] = -1 ; 
		v.pop_back() ; 
	}
}

int main( void )
{
	LoadMatrix() ; 
	Next_Permutations( 0 ) ; 
	cout << ans << "\n" ; 
}