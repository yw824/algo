#include <iostream>
using namespace std ;

// DP 사용

int n ;
int m ;
int** w ;
int** d ;

void Load()
{
  cin >> n >> m ;

  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;

  int sum ;

  for( int i = 1 ; i <= n ; ++i )
  {
    sum = 0 ;
    w[ i ] = new int[ m + 1 ]{ 0 } ;
    d[ i ] = new int[ m + 1 ]{ 0 } ;
    for( int j = 1 ; j <= m ; ++j )
    {
      cin >> w[ i ][ j ] ;
      sum += w[ i ][ j ] ;
      d[ i ][ j ] = sum ;
    }
  }
}

int Sum( int x1 , int y1 , int x2 , int y2 )
{
  int ans = 0 ;
  for( int i = x1 ; i <= x2 ; ++i )
    ans += ( d[ i ][ y2 ] - d[ i ][ y1 - 1 ] ) ;

  return ans ;
}

int main( void )
{
  Load() ;

  int test ;
  cin >> test ;

  int x1 , y1 , x2 , y2 ;
  while( test-- )
  {
    cin >> x1 >> y1 >> x2 >> y2 ;
    cout << Sum( x1 , y1 , x2 , y2 ) << "\n" ;
  }
}
