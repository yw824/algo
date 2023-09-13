#include <iostream>
#include <vector>
using namespace std ;

int ans ; 
int happy ; 
int n ; 
int health ; 
int** w ;
vector< int > v ;  

void LoadMatrix()
{
	cin >> n ; 
	w = new int*[ 2 ] ; 
	for( int i = 0 ; i < 2 ; i++ )
	{
		w[ i ] = new int[ n ]{ 0 } ; 
		for( int j = 0 ; j < n ; j++ )
			cin >> w[ i ][ j ] ; 
	}
	ans = 0 ; 
	happy = 0 ; 
	health = 100 ; 
}

void ShowData()
{
	for( int i = 0 ; i < 2 ; i++ )
	{
		for( int j = 0 ; j < n ; j++ )
			cout << w[ i ][ j ] << " " ;
		cout << "\n" ; 
	}
}

void Next_Permutations()
{
	if( happy > ans ) ans = happy ; 

	int stand ; 
	if( !v.size() ) stand = -1 ; 
	else stand = v.back() ; 
	for( int i = stand + 1 ; i < n ; i++ )
	{
		if( health - w[ 0 ][ i ] <= 0 ) // under the health
			continue ; 

		health -= w[ 0 ][ i ] ; 
		happy += w[ 1 ][ i ] ; 
		v.push_back( i ) ; 

		Next_Permutations() ; 

		health += w[ 0 ][ i ] ;
		happy -= w[ 1 ][ i ] ;  
		v.pop_back() ; 
	}
}

int main( void )
{
	LoadMatrix() ; 
	// ShowData() ; 

	Next_Permutations() ; 
	cout << ans << "\n" ; 
}