#include <iostream>
#include <string>
using namespace std ;

int main( void )
{
  string str ; // 주어진 문자열
  int N ; // 진법
  long long ans = 0 ; // 해답
  long long cnt = 1 ; // 진법 자릿수
  cin >> str >> N ;
  int len = (int)str.length() ;

  char c ;
  for( int i = len - 1 ; i >= 0 ; i-- )
  {
    c = str[ i ] ;
    if( c >= 48 && c <= 57 ) // 0 이상 9 이하
      ans += ( str[ i ] - 48 ) * cnt ;
    else // 알파벳
      ans += ( str[ i ] - 65 + 10 ) * cnt ;

    cnt *= N ;
  }
  cout << ans << "\n" ;
}
