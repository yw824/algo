#include <iostream>
#include <string>
#include <vector>
using namespace std ;

// 스택으로 사용할 벡터 이름 : s
// 알고리즘 : 층 수를 s.size() 로 구함
// '(' 들어올 시 : 스택에 추가해줌

// ')' 들어왔을 때 레이저 혹은 스틱 구분해야 함
// ')' 들어왔을 때 그 전의 문자가 바로 '(' 라면 레이저 - 들어오자마자 바로나감
// -> 그 밑의 개수만큼 총합에 더해줌 ( total += s.size() )
//    ( 레이저로 밑의 모든 스틱들이 모두 둘로 나눠졌기 떄문 )

// ')' 들어왔는데 그 전의 문자가 '(' 아니라면 바로 나가는거 아니므로
// 레이저가 아니라 스틱에 해당
// 현재 최상층의 스틱이 나가는 것이므로 total에 1 더해줌

vector< char > s ; // 스택
string str ; // 입력받는 문자열
int len ; // 입력받은 문자열의 길이

void Load()
{
  cin >> str ;
  len = int( str.length() ) ;
}

int getSticks()
{
  int total = 0 ; // total : 총합
  for( int i = 0 ; i < len ; i++ )
  {
    if( str[ i ] == '(' ) // '(' 들어왔을 경우 스택에 추가해줌
      s.push_back( str[ i ] ) ;

    else // ')' 들어왔을 때 : 레이저인지 스틱인지 구별해야 함
    {
      // 레이저일 때 자신 밑의 것들 size만큼만 더해줘야 하므로 미리 최상층 빼줌
      s.pop_back() ; // 일단 빼야 함 - 레이저이든 스틱이든 사이즈는 줄어들기 때문
      if( str[ i - 1 ] == '(' ) // 레이저 : 들어왔다가 바로 나감
        total += s.size() ; // 그 밑에거 개수만큼 더해줌 ( 레이저로 하나씩 나눠졌기 떄문 )
      else // 레이저가 아닐 때 : 스틱일 때
        total += 1 ; // 최상층 스틱 하나가 나가는 것이므로 총합에 하나 더해줌 , 사이즈는 하나 줄어듬
    }
  }

  return total ;
}

int main( void )
{
  Load() ;

  cout << getSticks() << "\n" ;
}
