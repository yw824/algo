#include <iostream>
using namespace std ;

int n ;
int* num ;

// DP 사용

void Load()
{
  cin >> n ;
  num = new int[ n + 1 ]{ 0 } ;
}

// num[ i ] =
// 셋 중 최소값 :
// num[ i - 1 ] + 1
// num[ i / 2 ] + 1
// num[ i / 3 ] + 1
void DP()
{
  for( int i = 2 ; i <= n ; i++ )
  {
    num[ i ] = num[ i - 1 ] + 1 ;

    if( !( i % 3 ) && num[ i / 3 ] + 1 < num[ i ] )
      num[ i ] = num[ i / 3 ] + 1 ;

    if( !( i % 2 ) && num[ i / 2 ] + 1 < num[ i ] )
      num[ i ] = num[ i / 2 ] + 1 ;
  }
}

int main( void )
{
  Load() ;

  DP() ;

  cout << num[ n ] ;
}
