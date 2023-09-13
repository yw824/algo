#include <iostream>
using namespace std ;

// DP 문제

int n ; // 집 개수
int** w ; // 입력받는 개별 집의 RGB 색칠 비용
int** d ; // 총 RGB 색칠 비용 계산 위한 DP 배열

// 현재 집에 R색을 칠할 때 최소 비용은
// 현재 집에 R색 칠하는 비용 +
// 처음부터 이전 집에서 G색 혹은 B색을 칠하는 것까지의 최소비용
// 처음부터 이전 집에서 G색 칠하기까지 최소비용 혹은 B색 칠하기까지 최소비용 중 더 작은 것

void Load()
{
  cin >> n ;
  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new int[ 3 ]{ 0 } ;
    d[ i ] = new int[ 3 ]{ 0 } ;

    for( int j = 0 ; j < 3 ; j++ )
      cin >> w[ i ][ j ] ;
  }

  d[ 1 ][ 0 ] = w[ 1 ][ 0 ] ; // 처음에는 각자 색 칠하는 것이 최소비용
  d[ 1 ][ 1 ] = w[ 1 ][ 1 ] ;
  d[ 1 ][ 2 ] = w[ 1 ][ 2 ] ;
}

int Mini( int a , int b ) // 둘 중에 더 작은 것 출력하는 함수
{
  if( a > b ) return b ;
  return a ;
}

void DP() // DP : 현재 R색을 칠한다면 그 비용은 R색비용 + 이전집의 G색까지 혹은 B색까지 중 최소비용
{
  for( int i = 2 ; i <= n ; i++ )
  {
    d[ i ][ 0 ] = w[ i ][ 0 ] + Mini( d[ i - 1 ][ 1 ] , d[ i - 1 ][ 2 ] ) ;
    d[ i ][ 1 ] = w[ i ][ 1 ] + Mini( d[ i - 1 ][ 2 ] , d[ i - 1 ][ 0 ] ) ;
    d[ i ][ 2 ] = w[ i ][ 2 ] + Mini( d[ i - 1 ][ 0 ] , d[ i - 1 ][ 1 ] ) ;
  }
}

int main( void )
{
  Load() ;

  DP() ;

  int ans = d[ n ][ 0 ] ; // 현재 집에서 R색 바를 때의 비용
  if( d[ n ][ 1 ] < ans ) ans = d[ n ][ 1 ] ; // 현재 집에서의 G색 바를 떄의 비용
  if( d[ n ][ 2 ] < ans ) ans = d[ n ][ 2 ] ; // 현재 집에서의 B색 바를 때의 비용

  cout << ans << "\n" ;
}
