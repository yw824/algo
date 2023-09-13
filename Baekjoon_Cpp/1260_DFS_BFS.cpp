#include <iostream>
using namespace std;

int n ; // 정점의 개수
int m ; // 간선의 개수
int v ; // 탐색을 시작할 정점의 번호 V

int** w ; // 인접 노드 표시할 배열
int* d ; // 방문 여부 저장할 배열

int* queue ; // BFS에서 사용할 큐
int front ; // BFS의 front 인덱스
int rear ; // BFS의 rear 인덱스

void LoadMatrix()
{
  // 정점갯수 - 간선갯수 - 시작할 노드 인덱스
  cin >> n >> m >> v ;

  // 방문 여부 배열 초기화
  d = new int[ n + 1 ] ;

  // 인접 여부 데이터 담는 배열 초기화
  w = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = new int[ n + 1 ]{ 0 } ;

  while( m-- )
  {
    int x1 , x2 ; cin >> x1 >> x2 ;
    // 인접노드이므로 양방향 모두 표시
    w[ x1 ][ x2 ] = 1 ; w[ x2 ][ x1 ] = 1 ;
  }
  
  // DFS 초기설정 - 시작 노드 방문여부 체크
  d[ v ] = 1 ;
}

// DFS 끝내고 BFS 초기화하는 과정
void BFS_Set()
{
  // DFS 끝났으므로 한 줄 떼기
  cout<< "\n" ;

  // 방문 여부 초기화
  for( int i = 1 ; i <= n ; i++ )
    d[ i ] = 0 ;

  // 시작값인 v 방문 체크하고 , 큐에 넣기
  d[ v ] = 1 ;
  queue = new int[ n + 1 ]{ 0 } ;

  // 큐에서 사용할 인덱스 초기화
  front = 0 ;
  rear = 1 ;
  queue[ front ] = v ;
}

// DFS
void DFS( int index )
{
  // 현재 노드 출력
  cout << index << " ";

  // 인접 노드 돌면서 방문 안한곳 있으면 방문
  for( int i = 1 ; i <= n ; i++ )
    if( !d[ i ] && w[ index ][ i ] )
    {
      d[ i ] = 1 ;
      DFS( i ) ;
    }
}

// BFS 종료조건 : 큐가 비어 있을 때
bool isEmpty() { return front == rear ; }

// BFS
void BFS()
{
  while( !isEmpty() )
  {
    // 현재 노드 탐색 : 출력
    cout << queue[ front ] << " ";

    // 만약 인접 노드 중 방문 안한거 있으면 순서대로 큐에 추가
    for( int i = 1 ; i <= n ; i++ )
      if( !d[ i ] && w[ queue[ front ] ][ i ] )
      {
        d[ i ] = 1 ; // 큐에 넣었거나 읽었다는 표시
        queue[ rear++ ] = i ; // 순서 : rear
      }
    // 큐의 다음 원소에 접근
    ++front ;
  }
}

int main(void)
{
  // 초기 데이터 받기 및 DFS 초기설정
  LoadMatrix() ;

  // DFS
  DFS( v ) ;

  // DFS 끝난 후 BFS 초기설정
  BFS_Set() ;

  // BFS
  BFS() ;
}
