#include <iostream>
using namespace std ; 

int n ; 
int* w ; 
int* prevmax ;
int* currmax ; 
int* prevmin ; 
int* currmin ; 
int ansmax ; 
int ansmin ;

int getMax( int a , int b , int c )
{
	int ans = a ; 
	if( ans < b ) ans = b ; 
	if( ans < c ) ans = c ; 
	return ans ; 
}

int getMin( int a , int b , int c )
{
	int ans = a ; 
	if( ans > b ) ans = b ; 
	if( ans > c ) ans = c ; 
	return ans ; 
}

void Load_DP()
{
	cin >> n ; 
	w = new int[ 3 ] ; 

	ansmax = 0 ; 
	ansmin = 27 * n ; 

	prevmax = new int[ 3 ]{ 0 } ;
	prevmin = new int[ 3 ]{ 0 } ;
	currmax = new int[ 3 ]{ 0 } ;
	currmin = new int[ 3 ]{ 0 } ;

	int i , j ; 
	for( i = 1 ; i <= n ; ++i )
	{ 
		for( j = 0 ; j < 3 ; ++j )
			cin >> w[ j ] ;  

		currmax[ 0 ] = getMax( prevmax[ 0 ] , prevmax[ 1 ] , 0 ) + w[ 0 ] ; 
		currmax[ 1 ] = getMax( prevmax[ 0 ] , prevmax[ 1 ] , prevmax[ 2 ] ) + w[ 1 ] ; 
		currmax[ 2 ] = getMax( prevmax[ 1 ] , prevmax[ 2 ] , 0 ) + w[ 2 ] ; 

		currmin[ 0 ] = getMin( prevmin[ 0 ] , prevmin[ 1 ] , 27 * n ) + w[ 0 ] ;
		currmin[ 1 ] = getMin( prevmin[ 0 ] , prevmin[ 1 ] , prevmin[ 2 ] ) + w[ 1 ] ;
		currmin[ 2 ] = getMin( prevmin[ 1 ] , prevmin[ 2 ] , 27 * n ) + w[ 2 ] ;

		prevmax[ 0 ] = currmax[ 0 ] ; 
		prevmax[ 1 ] = currmax[ 1 ] ; 
		prevmax[ 2 ] = currmax[ 2 ] ; 

		prevmin[ 0 ] = currmin[ 0 ] ; 
		prevmin[ 1 ] = currmin[ 1 ] ; 
		prevmin[ 2 ] = currmin[ 2 ] ;

		// cout << currmax[ 0 ] << " " << currmax[ 1 ] << " " << currmax[ 2 ] << " // " ; 
		// cout << currmin[ 0 ] << " " << currmin[ 1 ] << " " << currmin[ 2 ] << "\n" ; 
	}
	for( j = 0 ; j < 3 ; ++j )
	{
		if( ansmax < currmax[ j ] ) ansmax = currmax[ j ] ; 
		if( ansmin > currmin[ j ] ) ansmin = currmin[ j ] ; 
	}
}

int main( void )
{
	Load_DP() ;
	cout << ansmax << " " << ansmin << "\n" ; 
}