#include <iostream>
using namespace std ;

// dp : DP[ n ] = max( DP[ n ] , DP[ n - a ] + Arr[ a ] )
int n ;
int* arr ;
int* dp ;

void Load()
{
  cin >> n ;
  arr = new int[ n + 1 ]{ 0 } ;
  dp = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> arr[ i ] ;
    dp[ i ] = arr[ i ] ;
  }
}

int getMax( int a , int b )
{
  return ( a > b ? a : b ) ;
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << dp[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  Load() ;

  // dp
  for( int i = 2 ; i <= n ; i++ )
  {
    for( int j = 1 ; j < i ; j++ )
      dp[ i ] = getMax( dp[ i ] , dp[ i - j ] + arr[ j ] ) ;
  }

  cout << dp[ n ] << "\n" ;
  // ShowData() ;
}
