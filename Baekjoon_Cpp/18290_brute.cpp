#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

int** w ; // 입력 배열 
bool** checked ; // 포함 여부 저장하는 배열 
int n ; // 가로 n
int m ; // 세로 m
int k ; // 최대 k개 고르기 
int ans ; // 정답 
vector< pair< int , int > > v ; // 선택한 각 지점 넣는 벡터  

void LoadMatrix()
{
	cin >> n >> m >> k ; 

	w = new int*[ n + 2 ] ;
	checked = new bool*[ n + 2 ] ;

	for( int i = 0 ; i <= n + 1 ; ++i )
	{
		w[ i ] = new int[ m + 2 ]{ 0 } ; 
		checked[ i ] = new bool[ m + 2 ]{ false } ;

		if( i >= 1 && i <= n )
		{
			for( int j = 1 ; j <= m ; ++j )
				cin >> w[ i ][ j ] ;
		}
	}
	ans = -1000000 ; 
}

void ShowData()
{
	for( int i = 0 ; i <= n + 1 ; ++i )
	{
		for( int j = 0 ; j <= m + 1 ; ++j )
			cout << w[ i ][ j ] << " " ;
		cout << "\n" ;
	}
}

void Check()
{
	int cnt = 0 ; 
	for( int i = 1 ; i <= n ; ++i )
		for( int j = 1 ; j <= m ; ++j )
			if( checked[ i ][ j ] )
				cnt += w[ i ][ j ] ; 

	if( cnt > ans )
		ans = cnt ; 
}

void ShowData2()
{
	vector< pair< int , int > >::iterator iter ; 
	for( iter = v.begin() ; iter != v.end() ; ++iter )
		cout << "( " << (*iter).first << " , " << (*iter).second << " ) " ; 
	cout << "\n" ; 
}

void Next_Permutation( int cnt )
{
	// ShowData2() ; 

	if( cnt == k )
	{
		Check() ; 
		return ; 
	}

	int x , y ; 
	if( !v.size() )
	{
		x = 1 ; 
		y = 0 ; // 그 다음인 (1, 1)부터 탐색할 예정 
	} 
	else
	{
		x = v.back().first ; 
		y = v.back().second ; 
	}

	for( int i = x ; i <= n ; ++i )
	{
		for( int j = 1 ; j <= m ; ++j )
		{
			if( x == i && j <= y ) // 현재 고른 것까지 가장 최근의 열보다는 더 뒤의 것을 포함해야 함 
				continue ; 

			if( checked[ i - 1 ][ j ] )
				continue ;
			if( checked[ i + 1 ][ j ] )
				continue ;
			if( checked[ i ][ j - 1 ] )
				continue ;
			if( checked[ i ][ j + 1 ] )
				continue ;

			v.push_back( make_pair( i , j ) ) ;
			checked[ i ][ j ] = true ; 

			Next_Permutation( cnt + 1 ) ;

			checked[ i ][ j ] = false ; 
			v.pop_back() ; 
		}
	}
}

int main( void )
{
	LoadMatrix() ; 
	// ShowData() ; // 입력까지 OK 

	Next_Permutation( 0 ) ; 
	cout << ans << "\n" ; 
}