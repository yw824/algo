#include <iostream>
using namespace std ;

int n ; // 정점 개수
int m ; // 간선 개수

int** w ; // 그래프 연결 상태 보여주는 배열
int* d ; // 그래프 방문 여부 저장하는 배열

int count ; // 연결 요소 개수

// 순차탐색 하면서 , 새 연결요소 있으면
// 그대로 DFS 실시

// 초기 배열 받는 함수
void LoadMatrix()
{
  cin >> n >> m ;

  // 배열 미리 할당
  w = new int*[ n + 1 ] ;
  d = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = new int[ n + 1 ]{ 0 } ;

  // 연결 상태 부여받는 과정
  int x , y ;
  for( int i = 1 ; i <= m ; i++ )
  {
    cin >> x >> y ;
    w[ x ][ y ] = 1 ; w[ y ][ x ] = 1 ;
  }

  // 연결 요소는 아직 방문 안했으므로 0 설정
  count = 0 ;
}

// 새로운 연결요소 발생했을 때부터
// 연결된 방문하지 않은 모든 방문요소 방문
void DFS( int x )
{
  d[ x ] = 1 ;
  for( int i = 1 ; i <= n ; i++ )
    if( !d[ i ] && w[ x ][ i ] )
      DFS( i ) ;
}

// BFS - 그래프 원소 처음부터 순차탐색
// 방문 안한거 있으면 새로운 연결요소 인식
void BFS()
{
  for( int i = 1 ; i <= n ; i++ )
    if( !d[ i ] )
    {
      // 새로운 연결요소 방문하였으므로 개수에 추가
      count++ ;
      DFS( i ) ;
    }
}

int main( void )
{
  LoadMatrix() ;

  BFS() ;

  cout << count << "\n" ;
}
