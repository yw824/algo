#include <iostream>
#include <vector>
using namespace std ;

int n ; // 수열 원소 개수
int* w ; // 수열 입력 배열
int* dp ; // 총 개수
vector< int >* value ; // 벡터 배열 
int ans ; // 가장 긴 부분 수열이 있는 인덱스 

void Load()
{
	cin >> n ; 
	w = new int[ n ] ; 
	dp = new int[ n ]{ 0 } ; 
	value = new vector< int >[ n ] ;

	for( int i = 0 ; i < n ; ++i ) 
		cin >> w[ i ] ; 

	ans = 0 ; 
}

// O(n^2)
void DP()
{
	int cnt = 0 ; 
	vector< int >::iterator iter ; 
	for( int i = 0 ; i < n ; ++i )
	{
		value[ i ].push_back( w[ i ] ) ;
		dp[ i ] += 1 ; 
		for( int j = i + 1 ; j < n ; ++j )
		{
			if( w[ j ] > w[ i ] && dp[ j ] < dp[ i ] )
			{
				dp[ j ] = dp[ i ] ; 
				value[ j ].clear() ; 
				for( iter = value[ i ].begin() ; iter != value[ i ].end() ; ++iter )
					value[ j ].push_back( *iter ) ;
			}
		}
		if( cnt < dp[ i ] )
		{
			cnt = dp[ i ] ; 
			ans = i ; 
		}
	}
}

void ShowData()
{
	vector< int >::iterator iter ; 
	for( int i = 0 ; i < n ; ++i )
	{
		cout << "( " << dp[ i ] << " ) // " ;
		for( iter = value[ i ].begin() ; iter != value[ i ].end() ; ++iter )
			cout << *iter << " " ;
		cout << "\n" ; 
	}
}

int main( void )
{
	Load() ; 
	DP() ; 
	// ShowData() ; 

	vector< int >::iterator iter ; 
	cout << dp[ ans ] << "\n" ;
	for( iter = value[ ans ].begin() ; iter != value[ ans ].end() ; ++iter )
		cout << *iter << " " ;
	cout << "\n" ; 
}