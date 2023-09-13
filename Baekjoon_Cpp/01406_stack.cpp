#include <iostream>
#include <string>
#include <stack>
using namespace std ;

stack< char > Left ; // 커서 왼쪽
stack< char > Right ; // 커서 오른쪽

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  string str ;
  cin >> str ;
  int len = ( int )str.length() ;
  for( int i = 0 ; i < len ; i++ )
    Left.push( str[ i ] ) ;
  /* Right of init */

  char c ;
  int test ;
  cin >> test ;
  while( test-- )
  {
    cin >> c ;

    if( c == 'L' ) // 커서 한 칸 왼쪽으로 옮김
    {
      if( Left.empty() )
        continue ;
      c = Left.top() ; // 왼쪽의 최상위 문자 하나 빼서
      Left.pop() ;
      Right.push( c ) ; // 오른쪽 최상위 스택에 추가
    }

    else if( c == 'D' ) // 커서 한 칸 오른쪽으로 옮김
    {
      if( Right.empty() )
        continue ;
      c = Right.top() ;
      Right.pop() ; // 오른쪽의 최상위 문자 하나 빼서
      Left.push( c ) ; // 왼쪽 스택의 최상위에 추가
    }

    else if( c == 'B' ) // 커서 왼쪽의 문자 하나 삭제
    {
      if( Left.empty() ) // 커서 왼쪽 없으면 그냥 유지
        continue ;
      Left.pop() ; // 왼쪽 스택의 최상위 문자 하나 삭제
    }

    else if( c == 'P' ) // 커서 왼쪽에 내용 하나 추가
    {
      cin >> c ;
      Left.push( c ) ; // 왼쪽 스택으 최상위에 문자 하나 추가
    }
  }

  while( !Left.empty() ) // 왼쪽의 문자를 모두 오른쪽으로 넘기기
  {
    Right.push( Left.top() ) ;
    Left.pop() ;
  }

  while( !Right.empty() ) // 오른쪽 스택에서 하나씩 빼서 출력
  {
    cout << Right.top() ;
    Right.pop() ;
  }
}
