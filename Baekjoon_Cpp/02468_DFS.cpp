#include <iostream>
using namespace std ;

int maxh ;
int n ;
int** w ;
int** d ;
int ans ;

void LoadMatrix()
{
  cin >> n ;
  w = new int*[ n + 2 ] ;
  d = new int*[ n + 2 ] ;

  maxh = 0 ; ans = 0 ;
  for( int i = 0 ; i <= n + 1 ; i++ )
  {
    w[ i ] = new int[ n + 2 ]{ 0 } ;
    d[ i ] = new int[ n + 2 ]{ 0 } ;
    if( !i || i == n + 1 )
      continue ;

    for( int j = 1 ; j <= n ; j++ )
    {
      cin >> w[ i ][ j ] ;
      if( w[ i ][ j ] > maxh )
        maxh = w[ i ][ j ] ;
    }
  }
}

void ShowData()
{
  for( int i = 0 ; i <= n + 1 ; i++ )
  {
    for( int j = 0 ; j <= n + 1 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

void Init()
{
  for( int i = 1 ; i <= n ; i++ )
    for( int j = 1 ; j <= n ; j++ )
      d[ i ][ j ] = 0 ;
}

void DFS( int i , int j , int k )
{
  d[ i ][ j ] = 1 ;
  if( !d[ i - 1 ][ j ] && ( w[ i - 1 ][ j ] - k > 0 ) )
    DFS( i - 1 , j , k ) ;
  if( !d[ i + 1 ][ j ] && ( w[ i + 1 ][ j ] - k > 0 ) )
    DFS( i + 1 , j , k ) ;
  if( !d[ i ][ j - 1 ] && ( w[ i ][ j - 1 ] - k > 0 ) )
    DFS( i , j - 1 , k ) ;
  if( !d[ i ][ j + 1 ] && ( w[ i ][ j + 1 ] - k > 0 ) )
    DFS( i , j + 1 , k ) ;
}

int main( void )
{
  LoadMatrix() ;
  // ShowData() ;

  int count ;
  for( int k = 0 ; k <= maxh ; k++ )
  {
    count = 0 ;
    for( int i = 1 ; i <= n ; i++ )
      for( int j = 1 ; j <= n ; j++ )
        if( !d[ i ][ j ] && ( w[ i ][ j ] - k > 0 ) )
        {
          ++count ;
          DFS( i , j , k ) ;
        }

    Init() ;
    if( count > ans ) ans = count ;
  }

  cout << ans << "\n" ;
}
