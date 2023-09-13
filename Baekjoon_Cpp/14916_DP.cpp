#include <iostream>
using namespace std ;

int n ;
int* w ;

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ]{ 0 } ;

  if( n >= 1 ) w[ 1 ] = 0 ;
  if( n >= 2 ) w[ 2 ] = 1 ;
  if( n >= 3 ) w[ 3 ] = 0 ;
  if( n >= 4 ) w[ 4 ] = 2 ;
  if( n >= 5 ) w[ 5 ] = 1 ;
}

void DP()
{
  if( n <= 5 ) return ;
  for( int i = 6 ; i <= n ; i++ )
  {
    if( w[ i - 2 ] ) w[ i ] = w[ i - 2 ] + 1 ;
    if( w[ i - 5 ] ) w[ i ] = w[ i - 5 ] + 1 ;
  }
}

int main( void )
{
  Load() ;
  DP() ;
  if( !w[ n ] ) cout << "-1" ;
  else cout << w[ n ] ;
}
