#include <iostream>
using namespace std ;

// https://tech.lonpeach.com/2017/11/12/Euclidean-algorithm/
// 유클리드 호제법

int gcd( int a , int b )
{
  int big = a , small = b ;
  if( b > a )
  {
    big = b ; small = a ;
  }

  int r ;
  while( 1 )
  {
    r = big % small ;
    if( !r )
      break ;
    big = small ;
    small = r ;
  }

  // cout << "gcd : " << small << "\n" ;
  return small ;
}

long long lcm( int a , int b )
{
  return a * b / gcd( a , b ) ;
}

int main( void )
{
    cin.tie(0), ios::sync_with_stdio(0);
    int test ;
    int a , b ;

    cin >> test ;
    while( test-- )
    {
      cin >> a >> b ;
      cout << lcm( a , b ) << "\n" ;
    }
}
