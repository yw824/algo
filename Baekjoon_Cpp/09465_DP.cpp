#include <iostream>
using namespace std ;

int n ;
int** w ;
int ans ;
long long** d ;

void Load()
{
  cin >> n ;
  w = new int*[ 2 ] ;
  d = new long long*[ 2 ] ;

  for( int i = 0 ; i < 2 ; i++ )
  { // 두 번쨰 이전것 까지 고려해야 하므로 미리 2칸 추가로 공간 부여한다. 
    w[ i ] = new int[ n + 2 ] ;
    d[ i ] = new long long[ n + 2 ]{ 0 } ;
    for( int j = 2 ; j <= n + 1 ; j++ )
      cin >> w[ i ][ j ] ;
  }

  ans = 0 ;
}

void UnLoad()
{
  for( int i = 0 ; i < 2 ; i++ )
  {
    delete[] w[ i ] ;
    delete[] d[ i ] ;
  }
  delete[] w ;
  delete[] d ;
}

long long getMax( long long a , long long b , long long c )
{
  long long temp = a ;
  if( temp < b ) temp = b ;
  if( temp < c ) temp = c ;
  return temp ;
}

void DP()
{
  for( int i = 2 ; i <= n + 1 ; i++ )
  { // 본인 이전 것도 포함아지만, 이전 것을 포함하지 않고 두 번쨰 0 , 1번 모두 고려해야 한다.
    d[ 0 ][ i ] = w[ 0 ][ i ] + getMax( d[ 1 ][ i - 1 ] , d[ 0 ][ i - 2 ] , d[ 1 ][ i - 2 ] ) ;
    d[ 1 ][ i ] = w[ 1 ][ i ] + getMax( d[ 0 ][ i - 1 ] , d[ 0 ][ i - 2 ] , d[ 1 ][ i - 2 ] ) ;
  }
  ans = d[ 0 ][ n + 1 ] ;
  if( ans < d[ 1 ][ n + 1 ] ) ans = d[ 1 ][ n + 1 ] ;
}

void ShowData()
{
  for( int i = 0 ; i < 2 ; i++ )
  {
    for( int j = 0 ; j <= n + 1 ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  int test ;
  cin >> test ;
  while( test-- )
  {
    Load() ;
    DP() ;
    // ShowData() ;
    cout << ans << "\n" ;
    UnLoad() ;
  }
}
