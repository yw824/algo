#include <iostream>
using namespace std;

int main( void )
{
  int test ;
  cin >> test ;

  while( test-- )
  {
    getchar() ;

    int n ;
    cin >> n ;

    long long sum = 0 ;
    long long temp = 0 ;

    // 받을 때마다 사탕을 분배하여 나누어 줄 수도 있다.
    for( int i = 0 ; i < n ; i++ )
    {
      cin >> temp ;
      sum = ( sum + temp ) % n ;
    }
    if( sum )
    {
      printf( "NO\n" ) ;
      continue ;
    }
    printf( "YES\n" ) ;
  }
}
