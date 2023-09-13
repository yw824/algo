#include <iostream>
using namespace std ;

long long** w ;
int n ;

void Load()
{
  cin >> n ;
  w = new long long*[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new long long[ 10 ]{ 0 } ;

    if( i == 1 )
    {
      for( int j = 0 ; j < 10 ; j++ )
        w[ i ][ j ] = 1 ;
      continue ;
    }

    for( int j = 0 ; j < 10 ; j++ )
    {
      if( !j )
       w[ i ][ j ] = w[ i - 1 ][ j + 1 ] ;
      else if( j == 9 )
        w[ i ][ j ] = w[ i - 1 ][ j - 1 ] ;
      else
        w[ i ][ j ] = ( w[ i - 1 ][ j - 1 ] + w[ i - 1 ][ j + 1 ] ) % 1000000000 ;
      w[ i ][ j ] %= 1000000000 ;
    }

  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j < 10 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  Load() ;
  // ShowData() ;
  long long ans = 0 ;
  for( int i = 1 ; i < 10 ; i++ )
    ans = ( ans + w[ n ][ i ] ) % 1000000000 ;
  cout << ans ;
}
