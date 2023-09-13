#include <iostream>
using namespace std ;

int n ; // 곡의 개수
int s ; // 시작 볼륨
int m ; // 최대 볼륨
int* w ; // 각 곡마다 볼륨 변경값
int** d ;
int ans ;

void Load()
{
  cin >> n >> s >> m ;
  w = new int[ n + 1 ]{ 0 } ;
  d = new int*[ n + 1 ] ;
  for( int i = 0 ; i <= n ; i++ )
  {
    if( i )
      cin >> w[ i ] ;
    d[ i ] = new int[ m + 1 ]{ 0 } ;
  }
  d[ 0 ][ s ] = 1 ;
  ans = -1 ;
}

void DP()
{
  for( int i = 1 ; i <= n ; i++ )
    for( int j = 0 ; j <= m ; j++ )
      if( d[ i - 1 ][ j ] )
      {
        if( j + w[ i ] <= m  )
          d[ i ][ j + w[ i ] ] = 1 ;
        if( j - w[ i ] >= 0 )
          d[ i ][ j - w[ i ] ] = 1 ;
      }
  for( int i = 0 ; i <= m ; i++ )
    if( d[ n ][ i ] )
      if( ans < i ) ans = i ;
}

void ShowData()
{
  for( int i = 0 ; i <= n ; i++ )
  {
    for( int j = 0 ; j <= m ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  Load() ;
  DP() ;
  // ShowData() ;
  cout << ans << "\n" ;
}
