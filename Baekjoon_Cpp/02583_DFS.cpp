#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

vector< int > v ;
int m ; // 가로
int n ; // 세로
int k ; // 직사각형 개수
int** w ; // 배열
int ans ; // 입력하는 표기
int total ;
// 방문했을 시 -1로 표기

void LoadMatrix()
{
  cin >> m >> n >> k ;
  w = new int*[ m ] ;
  for( int i = 0 ; i < m ; ++i )
  {
    w[ i ] = new int[ n ]{ 0 } ;
  }
  ans = 0 ; total = 0 ;
}

void Paint()
{
  int x1 , y1 , x2 , y2 ;
  while( k-- )
  {
    cin >> y1 >> x1 >> y2 >> x2 ;
    for( int i = x1 ; i < x2 ; i++ )
      for( int j = y1 ; j < y2 ; j++ )
        w[ i ][ j ] = 1 ;
  }
}

void ShowData()
{
  for( int i = 0 ; i < m ; i++ )
  {
    for( int j = 0 ; j < n ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

void DFS( int i , int j )
{
  ++ans ;
  w[ i ][ j ] = 1 ;

  if( i - 1 >= 0 )
    if( !w[ i - 1 ][ j ] )
      DFS( i - 1 , j ) ;

  if( i + 1 < m )
    if( !w[ i + 1 ][ j ] )
      DFS( i + 1 , j ) ;

  if( j - 1 >= 0 )
    if( !w[ i ][ j - 1 ] )
      DFS( i , j - 1 ) ;

  if( j + 1 < n )
    if( !w[ i ][ j + 1 ] )
      DFS( i , j + 1 ) ;
}

int main( void )
{
  LoadMatrix() ;
  Paint() ;
  // ShowData() ; // 입력까지 완료


  for( int i = 0 ; i < m ; ++i )
    for( int j = 0 ; j < n ; ++j )
      if( !w[ i ][ j ] )
      {
        total++ ;
        DFS( i , j ) ;
        v.push_back( ans ) ;
        ans = 0 ;
      }

  sort( v.begin() , v.end() ) ;
  cout << total << "\n" ; 
  for( vector< int >::iterator iter = v.begin() ; iter != v.end() ; ++iter )
    cout << *iter << " " ;
  cout << "\n" ;
}
