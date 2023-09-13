#include <iostream>
#include <string>
using namespace std ;

int main( void )
{
  string ain , bin ;
  char oper ;
  cin >> ain >> oper >> bin ;

  long long alen = ain.length() ; // a 길이
  long long blen = bin.length() ; // b 길이
  long long max = alen ; // 최대 길이
  long long min = blen ; // 최소 길이
  if( alen < blen ) // 최대와 최소 길이 구하기( 덧셈에 필요 )
  {
    max = blen ;
    min = alen ;
  }

  if( oper == '+' ) // 덧셈
  {
    if( max == min ) // 자릿수 같을 때 -> 자릿수 더해져 2로 시작
    {
      cout << 2 ;
      for( int i = max - 1 ; i >= 1 ; i-- )
        cout << 0 ;

    }
    else // 다를 때 : 최대 자릿수에서 1 나오고, min 자릿수에서 1 또 나온다.
    {
      cout << 1 ; // max 자릿수 1
      for( int i = max - min - 1 ; i >= 1 ; i-- ) // max와 min 자릿수 사이 0
        cout << 0 ;
      cout << 1 ; // min 자릿수 1
      for( int i = min - 1 ; i >= 1 ; i-- ) // min-1부터 1까지의 자릿수에 0
        cout << 0 ;
    }
  }
  else if( oper == '*' ) // 곱셈 : a자릿수 + b자릿수 - 1의 자릿수가 나온다.
  {
    long long len = alen + blen - 1 ;
    cout << 1 ;
    for( int i = len - 1 ; i >= 1 ; i-- )
      cout << 0 ;

  }
  cout << "\n" ;
}
