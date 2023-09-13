#include <iostream>
using namespace std ;

int min( int a , int b , int c)
{
  int min = 9999999;
  if( min > a ) min = a ;
  if( min > b ) min = b ;
  if( min > c ) min = c ;

  return min ;
}


int main( void )
{
  int n ;
  cin >> n ;
  int current ;
  cin >> current ;

  int* w = new int[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  int total = 0 ;
  for( int i = 0 ; i < n ; i++ )
  {
    total += min( abs( current - w[ i ] ) , 360 - current + w[ i ] , current + 360 - w[ i ] ) ;
    current = w[ i ] ;
  }
  cout << total ;
}
