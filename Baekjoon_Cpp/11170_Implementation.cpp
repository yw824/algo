#include <iostream>
using namespace std ;

int* arr ;

int getZeros( int x )
{
  int cnt = 0 ;
  while( x )
  {
    if( !( x % 10 ) )
      ++cnt ;
    x /= 10 ;
  }
  return cnt ;
}

void SetArr()
{
  arr = new int[ 1000001 ]{ 0 } ;
  arr[ 0 ] = 1 ;

  for( int i = 1 ; i <= 1000000 ; i++ )
  {
    arr[ i ] = getZeros( i ) ;
    arr[ i ] += arr[ i - 1 ] ; // i번째까지 0의 개수 누적합
  }
}

int main( void )
{
  SetArr() ;

  int test ; cin >> test ;

  int left ; int right ;
  while( test-- )
  {
    cin >> left >> right ;
    if( !right ) // 0부터 0까지 : 0만
      cout << 1 << "\n" ;
    else
      if( !left ) // 0부터 오른쪽 끝까지 : 오른쪽 값의 누적합
        cout << arr[ right ] << "\n" ;
      else // 오른쪽 인덱스의 누적합 - ( 왼쪽 인덱스 -1 까지의 누적합 )
        cout << arr[ right ] - arr[ left - 1 ] << "\n" ;
  }
}
