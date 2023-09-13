#include <iostream>
using namespace std ;

int test ; // 테스트  세트 개수
long long n ; // 매일 제공되는 사료량
long long total ; // 매일매일 섭취 총량
int day ; // 경과된 날짜

// 자신의 것 + 인접 두개 + 맞은편 * 6개
// -> 0 ~ 6번까지 순회를 4번하는 것과 같다.

void Load()
{
  total = 0 ;
  day = 1 ;
  // 첫날부터 총량 넘을 수도 있으니까 1로 설정

  cin >> n ;

  // 개별 양을 받을 때마다 총량에 더해준다.
  // 날이 지날 때마다 총량을 * 4 해주면 된다.
  long long temp ;
  for( int i = 0 ; i < 6 ; i++ )
  {
    cin >> temp ;
    total += temp ;
  }
}

// 날이 지날 때마다 총량을 * 4 해주면 된다.
void Sol()
{
  // 제공되는 총량이 더 적으면 while문 탈출
  while( n >= total )
  {
    day++ ;
    total *= 4 ;
  }
  // 부족해지는 날짜 출력
  cout << day << "\n" ;
}

int main( void )
{
  cin >> test ;

  // 테스크 케이스 수만큼 반복
  while( test-- )
  {
    Load() ;
    Sol() ;
  }
}
