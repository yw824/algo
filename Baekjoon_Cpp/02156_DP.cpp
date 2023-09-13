#include <iostream>
using namespace std ;

int n ;
long long* d ;
int* w ;

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ]{ 0 } ;
  d = new long long[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
    cin >> w[ i ] ;

  if( n >= 1 )
    d[ 1 ] = w[ 1 ] ;
  if( n >= 2 )
    d[ 2 ] = w[ 2 ] + d[ 1 ] ;
}

// left : w[ i ] + w[ i - 1 ] + d[ i - 3 ] -> 본인 , 그전 , 그리고 세번째 이전까지의 값
// right : w[ i ] + d[ i - 2 ] -> 본인, 두번째 이전까지의 값
// prev : w[ i - 1 ] -> 본인 것을 제외한 본인 이전까지의 값 : 본인을 더하지 않는 것이 이득일 경우도 있음 
int getBiggerNum( long long left , long long right , long long prev )
{
  long long ans = left ;
  if( ans < right ) ans = right ;
  if( ans < prev ) ans = prev ;
  return ans ;
}

void DP()
{
  for( int i = 3 ; i <= n ; i++ )
    d[ i ] = getBiggerNum( w[ i ] + w[ i - 1 ] + d[ i - 3 ] , w[ i ] + d[ i - 2 ] , d[ i - 1 ] ) ;
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << d[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  Load() ;
  DP() ;

  // ShowData() ;

  cout << d[ n ] << "\n" ;
}
