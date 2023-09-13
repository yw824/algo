#include <iostream>
#include <cmath>
using namespace std ;

int tests ;
int* test ;
int limit ;
int* f ;
long long* g ;

void set() ;
void unset() ;

int main( void )
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  // 이 코드 넣으니까 시간 116ms -> 68ms 로 줄어든다.

  set() ;

  for( int i = 0 ; i < tests ; i++ )
    cout << g[ test[ i ] ] << "\n" ;

  unset() ;
}

void set() // 최대값까지 약수 총합 구하기
{
  cin >> tests ;
  test = new int[ tests ] ; // 테스트 케이스 개수

  limit = 0 ;
  for( int a = 0 ; a < tests ; a++ )
  {
    cin >> test[ a ] ; // 테스트 케이스 입력
    if( limit < test[ a ] ) // 테스트 케이스 중 최대값 구하기
      limit = test[ a ] ;
  }

  f = new int[ limit + 1 ]{ 0 } ; // 최대값까지의 약수 저장하는 배열
  g = new long long[ limit + 1 ]{ 0 } ; // 약수 누적합 배열

  for( int i = 1 ; i <= limit ; i++ )
  {
    for( int j = 1 ; i * j <= limit ; j++ )
      f[ i * j ] += i ; // 최대값까지의 현재 인덱스가 약수로 속하는 값에 더해주기
    g[ i ] = g[ i - 1 ] + f[ i ] ;
    // 이전 누적합 + 현재 약수의 총합 -> 현재까지의 약수 총합
  }
}

void unset()
{
   delete[] test ;
   delete[] f ;
   delete[] g ;
}
