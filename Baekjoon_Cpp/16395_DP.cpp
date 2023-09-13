#include <iostream>
using namespace std ;

// DP 사용
// 배열 할당하다 잘못 할당하면 
// LoadofNULL 런타임에러 걸릴 수도 있음

int n ; // 파스칼 삼각형의 원하는 위치 줄
int k ; // 파스칼 삼각형의 개수
long long** w ; // 파스칼의 삼각형
// 최대 크기 30

// 초기 데이터 받기
void Load()
{
  cin >> n >> k ;
  w = new long long*[ n ] ;

  // 원하는 것 : ( n - 1 ) C ( k - 1 )
  // 따라서 n - 1 까지만 시도하면 된다.
  for( int i = 0 ; i < n ; i++ )
  {
    // 매 줄마다
    w[ i ] = new long long[ i + 1 ] ; // 0 ~ i 까지 배열 만들기
    w[ i ][ 0 ] = 1 ; // 양 끝은 1로 초기화
    w[ i ][ i ] = 1 ;
  }
}

// 파스칼의 삼각형을 기울이면
// 자신 위의 것과 자신 위의 왼쪽것을 더하면 자신의 값이 된다.
// Combination과 동일한 연산
void Pascal()
{
  // ( 1,0 ) , ( 1,1 ) 은 1로 초기화되어 있어
  // 2번쨰 줄부터 ( i , 1 ) ,,,, ( i , i - 1 ) 까지 연산하면 됨
  for( int i = 2 ; i < n ; i++ )
  {
    for( int j = 1 ; j < i ; j++ )
      w[ i ][ j ] = w[ i - 1 ][ j - 1 ] + w[ i - 1 ][ j ] ;
  }
}


int main( void )
{
  Load() ;
  Pascal() ;

  // 원하는 연산 : ( n - 1 ) C ( k - 1 )
  cout << w[ n - 1 ][ k - 1 ] ;
}
