#include <iostream>
using namespace std ;

int getMin( int a , int b , int c , int d )
{
  int ans = a ;
  if( ans > b ) ans = b ;
  if( ans > c ) ans = c ;
  if( ans > d ) ans = d ;
  return ans ;
}

int main( void )
{
  int x , y , w , h ;
  cin >> x >> y >> w >> h ;
  cout << getMin( abs( x - 0 ) , abs( y - 0 ) , abs( x - w ) , abs( y - h ) ) ;
}
