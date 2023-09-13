#include <iostream>
using namespace std ;

int n ;
int** w ;

// DP

void LoadMatrix()
{
  cin >> n ;
  w = new int*[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = new int[ 3 ]{ 0 } ;

  w[ 1 ][ 0 ] = 1 ;
  w[ 1 ][ 1 ] = 1 ;
  w[ 1 ][ 2 ] = 1 ;
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << w[ i ][ 0 ] << " " << w[ i ][ 1 ] << " " << w[ i ][ 2 ] << "\n" ;
}

// 0 ( n번째에서 왼쪽 있을 때 ) : w[ n ][ 0 ] = w[ n - 1 ][ 1 ] + w[ n - 1 ][ 2 ]
// 0 ( n번째에서 오른 있을 때 ) : w[ n ][ 1 ] = w[ n - 1 ][ 0 ] + w[ n - 1 ][ 2 ]
// 0 ( n번째에서 둘다 없을 때 ) : w[ n ][ 2 ] = w[ n - 1 ][ 1 ] + w[ n - 1 ][ 0 ] + w[ n - 1 ][ 2 ]


void DP()
{
  for( int i = 2 ; i <= n ; i++ )
  {
    w[ i ][ 0 ] = ( w[ i - 1 ][ 1 ] + w[ i - 1 ][ 2 ] ) % 9901 ;
    w[ i ][ 1 ] = ( w[ i - 1 ][ 0 ] + w[ i - 1 ][ 2 ] ) % 9901 ;
    w[ i ][ 2 ] = ( w[ i - 1 ][ 1 ] + w[ i - 1 ][ 0 ] + w[ i - 1 ][ 2 ] ) % 9901 ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  LoadMatrix() ;
  DP() ;
  // ShowData() ;
  cout << ( w[ n ][ 0 ] + w[ n ][ 1 ] + w[ n ][ 2 ] ) % 9901 << "\n" ;
}
