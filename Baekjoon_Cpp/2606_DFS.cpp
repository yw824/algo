#include <iostream>
using namespace std ;

int n ; // 원소 개수
int e ; // 간선 개수
int** w ; // 연결상태 표시하는 2차원 배열
int* d ; // 방문여부 저장하는 배열

void LoadMatrix()
{
  cin >> n >> e ;

  w = new int*[ n + 1 ] ;
  d = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = new int[ n + 1 ]{ 0 } ;

  int x1 , x2 ;
  while( e-- )
  {
    cin >> x1 >> x2 ;
    w[ x1 ][ x2 ] = 1 ; w[ x2 ][ x1 ] = 1 ;
  }
}

void DFS( int index )
{
  d[ index ] = 1 ;
  for( int i = 1 ; i <= n ; i++ )
    if( !d[ i ] && w[ index ][ i ] )
      DFS( i ) ;
}


int main(void)
{
  LoadMatrix() ;

  // 1번부터 시작
  DFS( 1 ) ;

  int sum = 0 ;
  for( int i = 1 ; i <= n ; i++ )
    if( d[ i ] )
      ++sum ;

  cout << sum - 1 ;
}
