#include <iostream>
using namespace std ;

int getTwos( int n )
{
  int count = 0 ;
  while( n % 2 == 0 )
  {
    n /= 2 ;
    ++count ;
  }
  return count ;
}

int getFives( int n )
{
  int count = 0 ;
  while( n % 5 == 0 )
  {
    n /= 5 ;
    ++count ;
  }
  return count ;
}

int getMin( int a , int b )
{
  return ( a > b ? b : a ) ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  int fives[ 501 ] = { 0, } ;
  int twos[ 501 ] = { 0, } ;

  int n ;
  cin >> n ;

  for( int i = 2 ; i <= n ; i++ )
  {
    fives[ i ] = fives[ i - 1 ] + getFives( i ) ;
    twos[ i ] = twos[ i - 1 ] + getTwos( i ) ;
  }

  cout << getMin( fives[ n ] , twos[ n ] ) << "\n" ;
}
