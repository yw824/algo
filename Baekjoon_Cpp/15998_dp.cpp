#include <iostream>
#include <vector>
using namespace std ;


int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  int test ;
  vector< long long > v ;
  int limit = 0 ;

  // input and set max_of_int
  cin >> test ;
  int n ;
  for( int i = 0 ; i < test ; i++ )
  {
    cin >> n ;
    v.push_back( n ) ;
    if( limit < n )
      limit = n ;
  }

  // dp - 법칙은 그냥 추이만 예상한 것
  long long w[ limit + 1 ] = { 0, } ;
  if( limit >= 1 )
    w[ 1 ] = 1 ;
  if( limit >= 1 )
    w[ 2 ] = 2 ;
  if( limit >= 3 )
    w[ 3 ] = 4 ;

  // 더해갈 수록 값이 커져가기 때문에 long long으로 자료형을 설정해야 함
  for( int i = 4 ; i <= limit ; i++ )
    w[ i ] = ( w[ i - 1 ] + w[ i - 2 ] + w[ i - 3 ] ) % 1000000009 ;

  for( int i = 0 ; i < v.size() ; i++ )
    cout << w[ v[ i ] ] << "\n" ;
}
