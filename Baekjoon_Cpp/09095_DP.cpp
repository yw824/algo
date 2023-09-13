#include <iostream>
using namespace std ;

// DP 사용

int n ; // 테스트 케이스 수
int* test ; // 각 테스트 케이스 저장 공간
int* dp ; // dp 계산값 저장하는 곳 - 최대 11까지

void Load()
{
  cin >> n ;
  test = new int[ n ] ;

  for( int i = 0 ; i < n ; i++ )
    cin >> test[ i ] ;

  dp = new int[ 12 ]{ 0 , 1 , 2 , 4 } ;
  // 1번째부터니까 배열 크기는 11 + 1 = 12
}

// n - 1 번째에서 각각의 값 뒤에 1을 더하고
// n - 2 번째에서 각각의 값 뒤에 2를 더하고
// n - 3 번째에서 각각의 값 뒤에 3을 더한다.
void DP()
{
  for( int i = 4 ; i <= 11 ; i++ )
    dp[ i ] = dp[ i - 1 ] + dp[ i - 2 ] + dp[ i - 3 ] ;
}

int main( void )
{
  Load() ;
  DP() ;

  for( int i = 0 ; i < n ; i++ )
    cout << dp[ test[ i ] ] << "\n" ;
}
