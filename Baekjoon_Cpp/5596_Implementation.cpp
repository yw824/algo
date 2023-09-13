#include <iostream>
using namespace std ;

int mink ; // 민국
int mank ; // 만세

int main( void )
{

  int n ;
  int total = 0  ;

  for( int i = 0 ; i < 4 ; i++ )
  {
    cin >> n ;
    total += n ;
  }
  mink = total ;
  total = 0 ;

  for( int i = 0 ; i < 4 ; i++ )
  {
    cin >> n ;
    total += n ;
  }
  mank = total ;

  if( mink > mank )
    cout << mink ;
  else
    cout << mank ;
}
