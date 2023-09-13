#include <iostream>
using namespace std ;

//DP 사용

int n ; // 배열 원소 개수
int* w ; // 각 단계에서의 저장하는 배열
int* d ; // 각 단계까지 누적 저장하는 배열

void Load()
{
  cin >> n ;
  w = new int[ n + 1 ]{ 0 } ;
  d = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
    cin >> w[ i ] ;

  // 초기 설정 : d[ 0 ] , d[ 1 ] , d[ 2 ]
  d[ 1 ] = w[ 1 ] ;
  d[ 2 ] = w[ 2 ] + w[ 1 ] ;
}

int max( int left , int right )
{
  if( left > right )
    return left ;
  return right ;
}

// DP
// 둘 중에 더 큰 값을 누적값으로 설정 , 어차피 해당 w[ i ]를 더하는 게 최대
// w[ i ] + w[ i - 1 ] + d[ i - 3 ] : 한 칸 이동
// w[ i ] + d[ i - 2 ] : 두 칸 이동
void DP()
{
  for( int i = 3 ; i <= n ; i++ )
    d[ i ] = max( w[ i ] + w[ i - 1 ] + d[ i - 3 ] , w[ i ] + d[ i - 2 ] ) ;
}

int main( void )
{
  Load() ;
  DP() ;

  // 최종 값 출력
  cout << d[ n ] << "\n" ;
}
