#include <iostream>
#include <vector>

using namespace std ; 

int* x ; // 각 치킨집 주소 x좌표 
int* y ; // 각 치킨집 주소 y좌표 
int** w ; // 지도 
int** comp ; // 비교할 지도 
int n ; // 배열 한 변 크기
int m ; // 선택할 최대 치킨집 
int chicks ; // 지도 내 킨집 개수 
int ans ; // 정답 거리 
int MAX ; // 임의의 큰 값 

vector< int > v ; // 선택한 치킨집을 저장하는 배열 

void LoadMatrix() ; 
void Permutations( int ) ; 
void Check() ; 
void Initialize() ; 
void setMinDistance( int ) ; 
void ShowData() ; 
void ShowMaps() ; 

int main( void )
{
	LoadMatrix() ;
	// ShowMaps() ;
	Permutations( 0 ) ;

	cout << ans << "\n" ; 
}

void LoadMatrix()
{
	MAX = 1000000 ; 
	ans = MAX ; 

	cin >> n >> m ; 

	w = new int*[ n + 1 ] ; 
	comp = new int*[ n + 1 ] ; 
	for( int i = 0 ; i <= n ; ++i )
	{
		w[ i ] = new int[ n + 1 ]{ 0 } ; 
		comp[ i ] = new int[ n + 1 ]{ 0 } ; 

		if( i > 0 && i <= n ) 
		{
			for( int j = 1 ; j <= n ; ++j )
				{
					cin >> w[ i ][ j ] ;
					if( w[ i ][ j ] == 2 )
						++chicks ; 
				}
		}
	}

	int temp = 0 ; 
	x = new int[ chicks ] ; 
	y = new int[ chicks ] ;
	for( int i = 1 ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= n ; ++j )
		{
			if( w[ i ][ j ] == 2 )
			{
				x[ temp ] = i ; 
				y[ temp ] = j ;
				++temp ; 
			}
		}
	}
}

void ShowMaps()
{
	cout << "-----------ShowData---------------\n" ; 
	for( int i = 1 ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= n ; ++j )
		{
			cout << w[ i ][ j ] << " " ; 
		}
		cout << "\n" ; 
	}

	cout << "\n" ; 
	for( int i = 0 ; i < chicks ; ++i )
		cout << "chicken[ " << i << " ] : [ " << x[ i ] << " , " << y[ i ] << " ]\n" ; 
	cout << "\n" ;  
}

void setMinDistance( int markets )
{
	int xloc = x[ markets ] ; 
	int yloc = y[ markets ] ;

	// cout << "markets[ " << markets << " ] : (" << xloc << " , " << yloc << ")\n" ; 

	int dist ; 

	for( int i = 1 ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= n ; ++j )
		{
			if( comp[ i ][ j ] == 0 )
				continue ; 
			dist = abs( xloc - i ) + abs( yloc - j ) ;
			if( comp[ i ][ j ] > dist )
				comp[ i ][ j ] = dist ; 
		}
	}
}

void ShowData()
{
	cout << "\n" ; 
	for( int i = 1 ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= n ; ++j )
			cout << comp[ i ][ j ] << " " ;
		cout << "\n" ;
	}

}

void Initialize()
{
	for( int i = 1 ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= n ; ++j )
		{
			if( w[ i ][ j ] == 1 ) // 집일 때 
			{
				comp[ i ][ j ] = MAX ;
				continue ; 
			} // 집이 아니라 빈 공간이거나 다른 치킨집이라면 
				comp[ i ][ j ] = 0 ; 
		}
	}
}

void Check()
{
	Initialize() ; 
	vector< int >::iterator iter ; 
	for( iter = v.begin() ; iter != v.end() ; ++iter )
	{
		setMinDistance( *iter ) ;
	}

	int result = 0 ; 

	// ShowData() ; 

	for( int i = 1 ; i <= n ; ++i )
		for( int j = 1 ; j <= n ; ++j )
			result += comp[ i ][ j ] ; 

	if( ans > result )
		ans = result ; 
}

void Permutations( int cnt )
{
	if( cnt > m )
		return ; 
	if( cnt != 0 )
		Check() ; 

	int stand ; 
	if( !v.size() )
		stand = -1 ;
	else 
		stand = v.back() ; 

	for( int i = stand + 1 ; i < chicks ; ++i )
	{
		v.push_back( i ) ;
		Permutations( cnt + 1 ) ;
		v.pop_back() ;
	}
}