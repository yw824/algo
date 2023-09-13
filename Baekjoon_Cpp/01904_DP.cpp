#include <iostream>
using namespace std ;

// DP 사용

int n ; // 자릿수
int* d ; // DP 배열

// 초기 설정
void Load()
{
  cin >> n ;
  d = new int[ n + 1 ]{ 0 } ;
  d[ 1 ] = 1 ;
  d[ 2 ] = 2 ;
}

// DP 이용
// i - 2 번째 원소들에는 뒤에 00 붙이고
// i - 1 번째 원소들에는 뒤에 1 붙여서
// i 번째 원소로 포함시키면 됨
void DP()
{
  for( int i = 3 ; i <= n ; i++ )
    d[ i ] = ( d[ i - 1 ] + d[ i - 2 ] ) % 15746 ;
}

int main( void )
{
  Load() ;
  DP() ;

  cout << d[ n ] % 15746 << "\n" ;
}
