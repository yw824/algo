#include <iostream>
using namespace std ;

int n ;
bool* w ;

void Load()
{
  cin >> n ;
  w = new bool[ n + 1 ]{ false } ;
  for( int i = 2 ; i <= n ; i++ )
    w[ i ] = !w[ i - 1 ] ;
}

int main( void )
{
  Load() ;
  if( w[ n ] )
    cout << "SK" ;
  else
    cout << "CY" ;
}
