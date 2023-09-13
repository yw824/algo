#include <iostream>
#include <string>
#include <vector>
using namespace std ;

// 알고리즘 :
// '(' 들어오면 스택에 넣고

// ')' 들어왔을 때 최상위 값이 1이면
// 레이저에 해당 ( 바로 들어오자마자 나가는 거 )
// -> 그 밑에 원소들 다 1씩 추가
// 다 1씩 추가하는 과정이 for문 하나 더 도는거 -> O(n^2) : 메모리 많이 소모

// ')' 들어왔을 때 최상위 값이 2 이상이면
// 레이저 아니고 실제 스틱에 해당
// -> 그 스틱 개수만큼 총합에 더해주고 스택 최상위 원소 꺼내기

vector< int > stack ; // 스택 사용
int top ; // 스택에서 최상위 인덱스
string str ; // 입력받는 문자열
int len ; // 입력받은 문자열의 길이

// 초기 데이터 받기
void Load()
{
  top = - 1 ;
  cin >> str ;
  len = int( str.length() ) ;
}

// 총 막대기 개수 구하기
int Stick()
{
  int ans = 0 ; // 처음에 총합은 0으로 설정
  for( int i = 0 ; i < len ; i++ )
  {
    if( str[ i ] == '(' ) // 새로운 스틱 혹은 레이저가 들어올 경우
    {
      stack.push_back( 1 ) ; // 일단 스택에 추가해줌
      ++top ;
    }
    else // ')' 가 들어올 때 : 레이저와 스틱을 구분해야 함
    {
      if( stack[ top ] == 1 ) // 최상위에서 한번도 안잘리고 바로 나감 : 레이저에 해당
        for( int i = 0 ; i < top ; i++ ) // 본인은 나가고 그 밑에거 하나씩 다 1추가
          stack[ i ] += 1 ;
      else // 레이저 아닐 때 : 최상위 원소가 2 이상일 때
        ans += stack[ top ] ; // 본인 나가면서 자신이 레이저로 나눠졌던 마디개수를 총합에 더해줌
      stack.pop_back() ;
      top-- ;
    }
  }
  return ans ; // 모두 끝나면 리턴
}

int main( void )
{
  Load() ;

  cout << Stick() << "\n" ;
}
