#include <iostream>
using namespace std ; 

int n ; 
int* w ;
int status ; 

void Load()
{
	cin >> n ; 
	w = new int[ n + 1 ]{ 0 } ; 
	cin >> w[ n ] ;
	status = false ;  
}

void DP()
{
	int stand = w[ n ] ;
	int temp , i ;  
	while( stand-- )
	{
		w[ n - 1 ] = stand ; 
		for( i = n - 2 ; i >= 1 ; --i )
		{
			w[ i ] = w[ i + 2 ] - w[ i + 1 ] ;
			if( w[ i ] <= 0 )
				break ; 
		}
		if( w[ 1 ] > 0 && w[ 2 ] > 0 && w[ 2 ] > w[ 1 ] ) // 무조건 2번째 날이 1번째 날보다 커야 함 
			status = true ; 
		if( !status )
			continue ; 
		break ; 
	}
	if( status )
		cout << w[ 1 ] << "\n" << w[ 2 ] << "\n" ; 
}

void ShowData()
{
	for( int i = 1 ; i <= n ; ++i )
		cout << w[ i ] << " " ;
	cout << "\n" ; 
}

int main( void )
{
	Load() ; 
	DP() ; 
	// ShowData() ; 
}