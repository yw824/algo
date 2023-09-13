#include <iostream>
#include <cmath>
using namespace std ;

// 소수
// Memoization 수행

int m ; // m이상
int n ; // n이하
bool* d ; // 배열

// 초기 설정
void Load()
{
  cin >> m >> n ;

  // d [ i ] 가 0일 때만 i가 소수
  d = new bool[ n + 1 ]{ 0 } ;
  d[ 1 ] = true ; // 1은 소수가 아니므로 true 설정
}

// 소수 판별
void Prime()
{
  // 1은 소수가 아니므로 2부터 시작 , n 의 루트값까지만 돌리면 됨
  // 제곱근을 기준으로 제곱근이 아닌 인수들은 짝을 가지고 있기 때문에
  // 루트 n보다 작은 수 탐색에서 곱하기 하면서 모두 삭제했을 것
  for( int i = 2 ; i <= sqrt( n ) ; i++ )
  {
    // i가 소수가 아닐 경우에 넘어가기
    if( d[ i ] ) continue ;

    // 아래 내용 : 만약 소수일 경우에

    // 해당 소수( i ) 기준으로 j를 2부터 1씩 증가하며 i * j <= n 이라면
    // 곱한 값들을 모두 합성수 처리.
    for( int j = 2 ; i * j <= n ; j++ )
      d[ i * j ] = true ;
  }
}

int main( void )
{
  Load() ;
  Prime() ;

  // m 이상 n 이하의 소수를 모두 출력
  for( int i = m ; i <= n ; i++ )
    if( !d[ i ] )
      cout << i << "\n" ;
}
