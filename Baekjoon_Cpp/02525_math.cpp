#include <iostream>
using namespace std ;

int main( void )
{
  int hour , min , input ;
  cin >> hour >> min ;
  cin >> input ;
  hour = ( hour + ( min + input ) / 60 ) % 24 ;
  min = ( min + input ) % 60 ;
  cout << hour << " " << min ;
}
