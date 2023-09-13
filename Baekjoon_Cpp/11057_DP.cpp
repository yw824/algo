#include <iostream>
using namespace std ;

int n ;
long long** w ;

void Load()
{
  cin >> n ;
  w = new long long*[ n + 1 ]{ 0 } ;

  for( int i = 0 ; i <= n ; i++ )
  {
    w[ i ] = new long long[ 10 ]{ 0 } ;
    w[ i ][ 0 ] = 1 ;
    if( i == 1 )
      for( int j = 0 ; j < 10 ; j++ )
        w[ i ][ j ] = 1 ;
  }
}

void DP()
{
  for( int i = 2 ; i <= n ; i++ )
  {
    for( int j = 1 ; j < 10 ; j++ )
    {
      w[ i ][ j ] = ( w[ i - 1 ][ j ] + w[ i ][ j - 1 ] ) % 10007 ;
    }
  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= 9 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  Load() ;
  DP() ;
  // ShowData() ;

  long long ans = 0 ;
  for( int i = 0 ; i <= 9 ; i++ )
    ans += w[ n ][ i ] ;

  cout << ans % 10007 << "\n" ;
}
