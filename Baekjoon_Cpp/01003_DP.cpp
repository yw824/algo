#include <iostream>
using namespace std ;

int test ; // 테스트 케이스 개수
long zero[ 41 ] ; // 0에게 접근하는 횟수
long one[ 41 ] ; // 1에게 접근하는 횟수

// DP_Fibonacci Function

// fibo( i ) = fibo( i - 1 ) + fibo( i - 2 )
void Fibonacci()
{
  // 초기 설정
  zero[ 0 ] = 1 ; one[ 0 ] = 0 ;
  zero[ 1 ] = 0 ; one[ 1 ] = 1 ;

  // 0 , 1번째는 초기화 완료
  // 2번째부터 루프문 돌리면 됨
  for( int i = 2 ; i <= 40 ; i++ )
  {
    zero[ i ] = zero[ i - 1 ] + zero[ i - 2 ] ;
    one[ i ] = one[ i - 1 ] + one[ i - 2 ] ;
  }
}

int main( void )
{
  cin >> test ;
  Fibonacci() ;

  int n ; // 테스트마다 입력되는 수
  while( test-- )
  {
    cin >> n ;

    cout << zero[ n ] << " " << one[ n ] << "\n" ;
  }
}
