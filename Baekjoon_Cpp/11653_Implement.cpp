#include <iostream>
using namespace std ;

int n ;

int main( void )
{
  cin >> n ;
  int div = 2 ;
  while( true )
  {
    if( n == 1 ) break ;
    while( !( n % div ) )
    {
      cout << div << "\n" ;
      n /= div ;
    }
    ++div ;
  }
}
