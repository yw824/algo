#include <iostream>
using namespace std ;

int main( void )
{
  int n  , result ;
  cin >> n >> result ;

  int count = 5 ;
  int temp ;

  while( count-- )
  {
    cin >> temp ;
    cout << temp - ( result * n ) << " " ;
  }

}
