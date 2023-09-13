#include <iostream>
using namespace std ;

// 소수
// Memoization 수행

int m ; // m이상
int n ; // n이하
int* d ; // 배열

int sum ; // 소수의 합
int minimum ; // 소수의 최솟값

// 초기 설정
void Load()
{
  cin >> m ; // m 이상
  cin >> n ; // n 이하

  // d [ i ] 가 0일 때만 i가 소수
  d = new int[ n + 1 ]{ 0 } ;
  d[ 1 ] = 1 ; // 1은 소수가 아니므로 1 설정

  sum = 0 ; // m 이상 n 이하의 소수의 합 -> 초기값 0
  minimum = -1 ; // 소수가 없을 때는 minimum = -1
}

// 소수 판별
void Prime()
{
  // 1은 소수가 아니므로 2부터 시작
  for( int i = 2 ; i <= n ; i++ )
  {
    // i가 소수가 아닐 경우에 넘어가기
    if( d[ i ] ) continue ;

    // 아래 내용 : 만약 소수일 경우에

    // m보다 크다면
    if( i >= m )
    {
      // 최소값일 때
      if( minimum == -1 )
        minimum = i ;

      // m 이상 n 이하이므로 sum에 더하기
      sum += i ;
    }

    // 해당 소수로 해당 수보다 큰 수들을 나눠본다.
    for( int j = i + 1 ; j <= n ; j++ )
      if( !( j % i ) ) // 만약 해당 소수로 나눠지는 수가 있으면
        d[ j ] = 1 ; // 그 수는 소수가 아니다.
  }
}

int main( void )
{
  Load() ;
  Prime() ;

  if( minimum == -1 ) // 문제 조건 : 소수가 없으면
  {
    cout << minimum << "\n" ; // -1 출력하고 끝내기
    return 0 ;
  }
  // 소수가 있으면 첫번째 줄에 소수의 총합
  // 두번째 줄에 최소인 소수 출력하고 끝내기
  cout << sum << "\n" << minimum ;
}
