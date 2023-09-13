#include <iostream>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std ;

int main( void )
{
  int a , b ;
  cin >> a >> b ;
  int div = 1 ;
  for( int i = 2 ; i <= MIN( a , b ) ; i++ )
    if( !(a%i) && !(b%i) )
      div = i ;
  a = a / div ;
  b = b / div ;

  cout << div << "\n" ;
  cout << div * a * b ;
}
