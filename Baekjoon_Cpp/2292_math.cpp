#include <iostream>
using namespace std;

long long n ;

// 1 : 1개
// 2 ~ 7 ( 6개 ) : 2
// 8 ~ 19 ( 12개 ) : 3
// ,,,,

int main(void)
{
  cin >> n ;

  long long count = 1 ;
  long long temp = 1 ;

  // 더 작을 경우에는 비교할 경계값인 temp에 추가
  // 1 -> 7 -> 19 -> ,,,
  // 각 경계값보다 작으면 n은 count만큼의 방 수를 거쳐야 함
  while ( temp < n )
  {
    temp += 6 * count ;
    ++count ;
  }
  cout << count << "\n" ;
}
