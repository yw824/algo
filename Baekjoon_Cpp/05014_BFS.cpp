#include <iostream>
#include <queue>
using namespace std ;

int f ; // 총 층수
int s ; // 맨 처음 층수
int g ; // 가야 하는 층수
int u ; // 한번에 올라갈 수 있는 층수
int d ; // 한번에 내려갈 수 있는 층수
int* build ; // 층수 최소 횟수 저장 배열
queue< int > q ; // 큐

void Load()
{
  cin >> f >> s >> g >> u >> d ;

  build = new int[ f + 1 ]{ -1 } ;
  for( int i = 0 ; i <= f ; i++ )
    build[ i ] = -1 ;

  build[ s ] = 0 ;
  q.push( s ) ;
}

void ShowData()
{
  for( int i = 1 ; i <= f ; i++ )
    cout << build[ i ] << " " ;
  cout << "\n" ;
}

void BFS()
{
  while( !q.empty() )
  {
    // printf("front : %d , build[ %d ] : %d\n" , q.front() , q.front() , build[ q.front() ] ) ;
    if( q.front() + u <= f )
      if( build[ q.front() + u ] == -1 )
      {
        build[ q.front() + u ] = build[ q.front() ] + 1 ;
        q.push( q.front() + u ) ;
      }
    if( q.front() - d >= 1 )
      if( build[ q.front() - d ] == -1 )
      {
        build[ q.front() - d ] = build[ q.front() ] + 1 ;
        q.push( q.front() - d ) ;
      }
    q.pop() ;
  }
}

int main( void )
{
  Load() ;
  // ShowData() ;
  BFS() ;
  if( build[ g ] == -1 )
    cout << "use the stairs" ;
  else
    cout << build[ g ] ;
}
