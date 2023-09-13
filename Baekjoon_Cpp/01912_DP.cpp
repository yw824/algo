#include <iostream>
using namespace std ;

// https://mtoc.tistory.com/41
// DP

int n ; // 입력받을 수
int* w ; // 입력받는 배열
int* d ; // dp 배열
int ans ;

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ] ;
  d = new int[ n + 1 ] ;

  w[ 0 ] = -1000 ;
  d[ 0 ] = -1000 ;

  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> w[ i ] ;
    d[ i ] = w[ i ] ; // 초기 DP값은 자기 자신만 선택한 값
  }
  ans = -1000 ;
}

// 이전까지 누적한 DP값과 자신을 더한 값이
// 자신보다 크다면 누적 DP + 자신값이 자신까지의 누적 DP값이 된다.
// 아니면 본인 그대로
// 그리고, 현재까지의 최대 값을 구하는 것이 최종 답 ( ans )

void DP()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    if( d[ i - 1 ] + w[ i ] > d[ i ] )
      d[ i ] = d[ i - 1 ] + w[ i ] ;
    if( ans < d[ i ] )
      ans = d[ i ] ;
    // cout << ans << "\n" ;
  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << d[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  Load() ;
  DP() ;
  // ShowData() ;
  cout << ans << "\n" ;

}
