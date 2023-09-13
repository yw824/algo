#include <iostream>
using namespace std ;

// n = 40 이상으로 가면 경우의 수가 많아져 long long 으로 해야 한다.

int n ; // 원하는 자릿수
long long* zero ; // 앞자리가 0일 경우라고 생각했을 때( 규칙 이외로 ) 이친수인 수
long long* one ; // 앞자리가 1이면서 이친수인 수

// DP 문제
// zero[ i ] = zero[ i - 1 ] + one[ i - 1 ]
// one[ i ] = zero[ i - 1 ]

// 예 )
// one[ 4 ] : 1000 , 1001 , 1010
// zero[ 4 ] : 0000 , 0001 , 0010 , 0100 , 0101
// one[ 5 ] : 10000 , 10001 , 10010 , 10100 , 10101
// zero[ 5 ] : 00000 , 00001 , 00010 , 00100 , 00101 ( 0_zero[4] ) // 01000 , 01001 , 01010 ( 0_one[4] )

void Load() // 초기 내용 저장하는 배열
{
  cin >> n ;

  zero = new long long[ n + 1 ]{ 0 } ;
  one = new long long[ n + 1 ]{ 0 } ;

  zero[ 1 ] = 1 ; zero[ 2 ] = 2 ;
  one[ 1 ] = 1 ; one[ 2 ] = 1 ;
}

void ShowData() // 배열 데이터 출력
{
  cout << "zero : " ;
  for( int i = 1 ; i <= n ; i++ )
    cout << zero[ i ] << " " ;

  cout << "\n" << "one : " ;
  for( int i = 1 ; i <= n ; i++ )
    cout << one[ i ] << " " ;
}

void DP() // Dynamic Programming 으로 문제 해결
{  // 1 , 2번째 인덱스는 미리 설정 , 그다음부터 차례로 넘어가면서 처리
  for( int i = 3 ; i <= n ; i++ )
  {
    one[ i ] = zero[ i - 1 ] ;
    zero[ i ] = one[ i - 1 ] + zero[ i - 1 ] ;
  }
  cout << one[ n ] << "\n" ; // 원하는 인덱스에서의 이친수 출력
}

int main( void )
{
  Load() ;
  // ShowData() ;

  DP() ;
}
