#include <iostream>
#include <vector>
using namespace std ;

int n ; 
int* w ; 
vector< int > v ; 
int ans ; 
int limit ; 

void Load()
{
	cin >> n >> limit ; 

	w = new int[ n ] ; 
	for( int i = 0 ; i < n ; ++i )
		cin >> w[ i ] ;

	ans = 0 ; 
}

void Check()
{
	int total = 0 ; 
	vector< int >::iterator iter ; 
	for( iter = v.begin() ; iter != v.end() ; ++iter )
		total += w[ *iter ] ;

	if( total > limit )
		return ;

	if( ans < total )
		ans = total ; 
}

void Next_Permutations( int cnt )
{
	if( cnt == 3 )
	{
		Check() ; 
		return ;
	}

	int stand ; 
	if( v.size() == 0 )
		stand = -1 ; 
	else 
		stand = v.back() ; 

	for( int i = stand + 1 ; i < n ; ++i )
	{
		v.push_back( i ) ; 
		Next_Permutations( cnt + 1 ) ; 
		v.pop_back() ; 
	}
}

int main( void )
{
	Load() ; 
	Next_Permutations( 0 ) ; 
	cout << ans << "\n" ; 
}