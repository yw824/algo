#include <iostream>
using namespace std ;

int n ; // 친구의 수
int m ; // 친구 관계의 수

int** w ; // 연결 관계 지정한 배열
int* d ; // 방문 단계 저장한 배열 - 방문 안했을 때 -1
int count ; // 방문 과정 중 가장 작은 케빈베이컨 수 저장하는 배열
int ans ; // 제일 작은 케빈베이컨 수 가진 인덱스

int* queue ; // BFS에서 사용할 큐
int front ; // BFS의 front 인덱스
int rear ; // BFS의 rear 인덱스

void LoadMatrix()
{
  cin >> n >> m ;

  count = 999 ;

  d = new int[ n + 1 ]{ 0 } ;
  w = new int*[ n + 1 ] ;
  queue = new int[ n ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new int[ n + 1 ]{ 0 } ;
    d[ i ] = -1 ; // 첫 방문으로 주어지는 수가 0단계이므로 시작 안하면 -1로 설정
  }

  int x , y ;
  for( int i = 0 ; i < m ; i++ )
  {
    cin >> x >> y ;
    w[ x ][ y ] = 1 ; w[ y ][ x ] = 1 ;
  }
}

void Initialize( int index )
{

  for( int i = 1 ; i <= n ; i++ )
  {
    d[ i ] = -1 ;
    queue[ i - 1 ] = 0 ;
  }

  queue[ rear ] = index ;
  front = 0 ; rear = 1 ;
  d[ index ] = 0 ;
}

bool isEmpty() { return front == rear ; }

void BFS( int index , int count )
{
  ++front ;
  d[ index ] = count ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if( d[ i ] == -1 && w[ index ][ i ] )
    {
      queue[ rear++ ] = i ;
      d[ i ] = count + 1 ;
    }
  }
  if( !isEmpty() )
    BFS( queue[ front ] , d[ queue[ front ] ]  ) ;
}

int main( void )
{
  LoadMatrix() ;

  for( int i = 1 ; i <= n ; i++ )
  {
    Initialize( i ) ;
    BFS( i , 0 ) ;

    /*
    cout << "i : " << i << "\n" ;
    for( int j = 1 ; j <= n ; j++ )
      printf(" d[ %d ] : %d \n" , j , d[ j ] ) ;
    cout << "------------------\n" ;
    */

    int result = 0 ;
    for( int j = 1 ; j <= n ; j++ )
        result += d[ j ] ;

    if( count > result )
    {
      count = result ;
      ans = i ;
    }
  }

  cout << ans << "\n" ;
}
