#include <iostream>
using namespace std ;

// https://mapocodingpark.blogspot.com/2020/01/11055.html

int N ;  
int arr[ 1000 ] ;
int dp[ 1000 ] ;  
int ans ;

int main( void )
{
	ios_base::sync_with_stdio(false) ; 
	cout.tie(NULL) ; 
	cin.tie(NULL) ;

	cin >> N ;

	for ( int i = 0 ; i < N ; ++i ) 
	{
		cin >> arr[ i ] ;
		dp[ i ] = arr[ i ] ;
		for ( int j = 0 ; j < i ; ++j ) // 본인 이전 것들과 비교 
		{
			if( arr[ i ] > arr[ j ] ) // 만약 본인보다 해당 인덱스의 증가 수열 입력값이 작다면 증가 수열에 포함 
			{
				dp[ i ] = max(dp[ i ] , dp[ j ] + arr[ i ] ) ; // 본인과, 본인 이전 인덱스까지의 증가 수열과 비교 
			}
		}
		ans = max( ans , dp[ i ] ) ;
	}

	cout << ans << '\n' ;

	return 0;
}