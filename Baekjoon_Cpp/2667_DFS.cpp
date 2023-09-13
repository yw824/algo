#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int n ;
int** w ; // 지도 저장하는 배열
int** d ; // 각 원소마다 방문 여부 체크
vector< int > v ; // 단지 수 넣는 배열
int sum ; // DFS 실행 시 임시로 단지 수 저장하는 변수

void LoadMatrix()
{
  cin >> n ;
  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
  {
    d[ i ] = new int[ n + 1 ]{ 0 } ;
    w[ i ] = new int[ n + 1 ]{ 0 } ;

    string str ;
    cin >> str ;
    for( int j = 1 ; j <= n ; j++ )
      w[ i ][ j ] = ( int )( str[ j - 1 ] ) - 48 ;
  }
}

void ShowData()
{
  cout << "n : " << n << endl ;
  cout << "---------w[i][j]--------\n" ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << endl ;
  }
  cout << "---------d[i][j]--------\n" ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << endl ;
  }
}

void DFS( int x , int y )
{
  sum++ ;
  d[ x ][ y ] = 1 ;

  if( x - 1 >= 1 && !d[ x - 1 ][ y ] && w[ x - 1 ][ y ] == 1 )
    DFS( x - 1 , y ) ;
  if( y - 1 >= 1 && !d[ x ][ y - 1 ] && w[ x ][ y - 1 ] == 1 )
    DFS( x , y - 1 ) ;
  if( x + 1 <= n && !d[ x + 1 ][ y ] && w[ x + 1 ][ y ] == 1 )
    DFS( x + 1 , y ) ;
  if( y + 1 <= n && !d[ x ][ y + 1 ] && w[ x ][ y + 1 ] == 1 )
    DFS( x  , y + 1 ) ;
}

int main( void )
{
  LoadMatrix() ;
  // ShowData() ;

  sum = 0 ;

  for( int i = 1 ; i <= n ; i++ )
    for( int j = 1 ; j <= n ; j++ )
    {
      if( !d[ i ] [ j ] && w[ i ][ j ] )
      {
        DFS( i , j  ) ;
        v.push_back( sum ) ;
      }
      d[ i ][ j ] = 1 ;
      sum = 0 ;
    }

  cout << v.size() << "\n" ;

  sort( v.begin() , v.end() ) ;
  for( vector<int>::iterator iter = v.begin() ; iter != v.end() ; ++iter )
    cout << (*iter) << "\n" ;
}
