#include <iostream>
#include <vector>
using namespace std ;

int n ; 
int* w ; 
int* d ; 
vector< int > v ; 

void Load()
{
	cin >> n ; 
	w = new int[ n ] ;
	d = new int[ n ] ; 
	for( int i = 0 ; i < n ; ++i )
	{
		cin >> w[ i ] ; 
		d[ i ] = -1 ; 
	}
}

void DP()
{
	int temp ; 
	v.push_back( 0 ) ;  
	for( int i = 1 ; i < n ; ++i )
	{
		while( v.size() != 0 && w[ v.back() ] < w[ i ] )
		{
			temp = v.back() ;
			d[ temp ] = w[ i ] ;
			v.pop_back() ; 
			
		}
		v.push_back( i ) ;
	}
}

void ShowData()
{
	for( int i = 0 ; i < n ; ++i )
		cout << d[ i ] << " " ; 
	cout << "\n" ; 
}

int main( void )
{
	Load() ; 
	DP() ; 
	ShowData() ; 
}