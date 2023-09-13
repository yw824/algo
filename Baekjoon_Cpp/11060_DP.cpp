#include <iostream>
using namespace std ;

int n ;
int* w ;
int* d ;

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ] ;
  d = new int[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> w[ i ] ;
    d[ i ] = 1001 ;
  }
  d[ 1 ] = 0 ;
}

void DP()
{
  int step ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if( d[ i ] == 1001 )
      continue ;

    step = w[ i ] ;
    for( int j = 1 ; j <= step ; j++ )
      if( i + j <= n && d[ i + j ] > d[ i ] + 1 )
        d[ j + i ] = d[ i ] + 1 ;
  }
}

int main( void )
{
  Load() ;
  DP() ;
  if( d[ n ] == 1001 )
    cout << -1 << "\n" ;
  else
    cout << d[ n ] << "\n" ;
}
