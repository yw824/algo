#include <iostream>
using namespace std ;

int main( void )
{
  int a , b , c ;
  cin >> a >> b >> c ;

  int same = 0 ;
  if( a == b ) same++ ;
  if( a == c ) same++ ;
  if( b == c ) same++ ;

  if( same == 3 )
    cout << 10000 + a * 1000 ;
  else if( same == 1 )
  {
    if( a == b || a == c )
      cout << 1000 + a * 100 ;
    else
      cout << 1000 + b * 100 ;
  }
  else
  {
    int temp = a ;
    if( temp < b ) temp = b ;
    if( temp < c ) temp = c ;
    cout << temp * 100 ;
  }
}
