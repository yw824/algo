#include <iostream>
using namespace std ;

int n ;
int m ;
int** w ;
int** d ;

void LoadMatrix()
{
  cin >> n >> m ;

  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;

  for( int i = 0 ; i <= n ; i++ )
  {
    w[ i ] = new int[ m + 1 ]{ 0 } ;
    d[ i ] = new int[ m + 1 ]{ 0 } ;
    if( !i ) continue ;
    for( int j = 1 ; j <= m ; j++ )
      cin >> w[ i ][ j ] ;
  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= m ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int MAX( int a , int b , int c )
{
  int ans = a ;
  if( ans < b ) ans = b ;
  if( ans < c ) ans = c ;
  return ans ;
}

void DP()
{
  for( int i = 1 ; i <= n ; i++ )
    for( int j = 1 ; j <= m ; j++ )
      d[ i ][ j ] = MAX( d[ i - 1 ][ j ] , d[ i ][ j - 1 ] , d[ i - 1 ][ j - 1 ] ) + w[ i ][ j ] ;
}

int main( void )
{
  LoadMatrix() ;
  // ShowData() ;
  DP() ;

  cout << d[ n ][ m ] << "\n" ;
}
