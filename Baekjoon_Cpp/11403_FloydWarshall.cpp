#include <iostream>
using namespace std ;

// Floyd_Warshall 알고리즘

int n ; // 정점의 개수
int** w ; // 인접 배열


// 초기 데이터 받아오기( 문제에서 주어지는 대로 )
void LoadMatrix()
{
  cin >> n ;

  w = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new int[ n + 1 ] ;
    for( int j = 1 ; j <= n ; j++ )
      cin >> w[ i ][ j ] ;
  }
}


// 중간에 x를 거쳐 가는 경로 있으면
// 다이렉트로 가는 경로가 있는 것으로 간주
void Floyd_W( int x )
{
  for( int i = 1 ; i <= n ; i++ )
  {
    // i에서 x까지 오는 경로 있고 , x에서 j까지 오는 경로 있으면
    for( int j = 1 ; j <= n ; j++ )
      if( w[ i ][ x ] && w[ x ][ j ] )
        w[ i ][ j ] = 1 ;
        // i에서 j까지 가는 경로 있다고 표시.
  }
}


// Floyd_Warshall 끝난 후 데이터 출력
void ShowData()
{
  // cout << "-------------------------------\n" ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  LoadMatrix() ;


  // 중간에 기준이 되는 x를 1부터 n까지 순차로 돌리기
  for( int i = 1 ; i <= n ; i++ )
    Floyd_W( i ) ;


  ShowData() ;
}
