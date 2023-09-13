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
    d[ i ] = w[ i ] ;
  }
}

int getMin( int a , int b )
{
  return ( a > b ? b : a ) ;
}

void DP()
{
  for( int i = 2 ; i <= n ; i++ )
    for( int j = 1 ; j < i ; j++ )
      d[ i ] = getMin( d[ i ] , d[ i - j ] + w[ j ] ) ;
}

int main( void )
{
  Load() ;
  DP() ;

  cout << d[ n ] << "\n" ;
}
