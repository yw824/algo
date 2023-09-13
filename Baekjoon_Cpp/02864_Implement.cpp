#include <iostream>
using namespace std ;

int getMax( int a , int b )
{
  int tempa ;
  int tempb ;
  int temp = 0 ;

  int ans = 0 ;
  int pos = 1 ;
  while( a + b + temp )
  {
    tempa = a % 10 ;
    tempb = b % 10 ;
    if( tempa == 5 ) tempa += 1 ;
    if( tempb == 5 ) tempb += 1 ;

    ans += ( ( tempa + tempb + temp ) % 10 ) * pos ;
    temp = ( tempa + tempb + temp ) / 10 ;

    a /= 10 ;
    b /= 10 ;
    pos *= 10 ;
  }
  return ans ;
}

int getMin( int a , int b )
{
  int tempa ;
  int tempb ;
  int temp = 0 ;

  int ans = 0 ;
  int pos = 1 ;
  while( a + b + temp )
  {
    tempa = a % 10 ;
    tempb = b % 10 ;
    if( tempa == 6 ) tempa -= 1 ;
    if( tempb == 6 ) tempb -= 1 ;

    ans += ( ( tempa + tempb + temp ) % 10 ) * pos ;
    temp = ( tempa + tempb + temp ) / 10 ;

    a /= 10 ;
    b /= 10 ;
    pos *= 10 ;
  }
  return ans ;
}

int main( void )
{
  int a , b ;
  cin >> a >> b ;

  int left = getMin( a , b ) ;
  int right = getMax( a , b ) ;
  cout << left << " " << right ;
}
