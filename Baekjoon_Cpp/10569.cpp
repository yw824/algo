#include <iostream>
using namespace std ;

int main( void )
{
  int t , v , e ;

  cin >> t ;

  while( t-- )
  {
    cin >> v >> e ;
    printf( "%d\n" , 2 + e - v ) ;
  }
}
