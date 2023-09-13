#include <iostream>
using namespace std ;

int* w ;
int n ;

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ]{ 0 } ;
  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = i ;
}

void DP( int in )
{
  w[ in * in ] = 1 ;
  for( int i = in * in + 1 ; i <= n ; i++ )
    if( w[ i ] > w[ i - in * in ] + 1 )
      w[ i ] = w[ i - in * in ] + 1 ;
}

int main( void )
{
  Load() ;
  for( int i = 2 ; i * i <= n ; i++ )
    DP( i ) ;
  cout << w[ n ] << "\n" ;
}
