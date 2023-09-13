#include <iostream>
using namespace std ;

// https://astrid-dm.tistory.com/280

int n ; 
int m ; 
int** w ; 
long long** dp ;

void LoadMatrix() 
{
	cin >> n >> m ; 
	w = new int*[ n + 1 ] ;
	dp = new long long*[ n + 1 ] ;  

	int i , j ;  
	for( i = 0 ; i <= n ; ++i )
	{
		w[ i ] = new int[ m + 1 ]{ 0 } ; 
		dp[ i ] = new long long[ m + 1 ]{ 0 } ; 
		if( i == 0 )
			continue ; 

		// 여기서 한 번 에 계산하고 
		for( j = 1 ; j <= m ; ++j )
		{
			cin >> w[ i ][ j ] ; 
			dp[ i ][ j ] = w[ i ][ j ] + dp[ i - 1 ][ j ] + dp[ i ][ j - 1 ] - dp[ i - 1 ][ j - 1 ] ;
		}
	}
}

void getPopulation()
{
	int test ; 
	cin >> test ; 
	int a , b , c , d ; 
	while( test > 0 )
	{
		cin >> a >> b >> c >> d ; 
		// 여기서도 계산이 한 번에 이루어져야 한다. 
		cout << dp[ c ][ d ] - dp[ a - 1 ][ d ] - dp[ c ][ b - 1 ] + dp[ a - 1 ][ b - 1 ] << "\n" ;
		--test ; 
	}
}

int main( void )
{
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);

	LoadMatrix() ; 
	getPopulation() ;
}