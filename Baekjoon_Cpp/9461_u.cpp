#include <iostream>
using namespace std ;

// 배열을 long long 으로 해야 한다.
int test ;
long long p[101] ;

// 수학적 원리는 잘 모르겠지만
// p[ i ] = p[ i - 2 ] + p[ i - 3 ] 으로 하면 맞다.
void DP()
{
  p[ 1 ] = 1 ;
  p[ 2 ] = 1 ;
  p[ 3 ] = 1 ;
  for( int i = 4 ; i <= 100 ; i++ )
    p[ i ] = p[ i - 2 ] + p[ i - 3 ] ;
}

// DP 사용
int main( void )
{
  DP() ;

  cin >> test ;

  int n ;
  while( test-- )
  {
    cin >> n ;
    cout << p[ n ] << "\n" ;
  }
}
