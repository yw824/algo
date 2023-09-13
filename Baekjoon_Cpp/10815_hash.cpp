#include <iostream>
using namespace std ;

bool w[ 20000001 ] = { false, };

int main( void )
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n = 1 , test = 1 ;
  cin >> n ;
  for( int i = 0 ; i < n ; i++ )
  {
    cin >> test ;
    w[ test + 10000000 ] = true ;
  }

  cin >> test ;
  for( int i = 0 ; i < test ; i++ )
  {
    cin >> n ;
    cout << w[ n + 10000000 ] << " " ;
  }
}
