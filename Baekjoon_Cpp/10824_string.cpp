#include <iostream>
#include <string>
using namespace std ;

string front ;
string back ;
string ans ;

void Load_Concat()
{
  string a , b , c , d ;
  cin >> a >> b >> c >> d ;
  front = a + b ;
  back = c + d ;
}

// '0' = 48
void Sum()
{
  ans = "" ;
  int len ;
  int alen = int( front.length() ) ;
  len = alen ;
  int blen = int( back.length() ) ;
  if( len < blen )
  {
    len = blen ;
    for( int i = 1 ; i <= len - alen ; i++ )
      front = "0" + front ;
  }
  else
    for( int i = 1 ; i <= len - blen ; i++ )
      back = "0" + back ;
  // 자릿수 맞추기까지 완료

  int temp = 0 , sub;
  for( int i = len - 1 ; i >= 0 ; i-- )
  {
    sub = ( temp + back[ i ] - 48 + front[ i ] - 48 )  ;
    // cout << " i : " << sub << "\n" ;
    ans = char( sub % 10 + 48 ) + ans ;
    temp = sub / 10 ;
  }
  if( temp == 1 )
  ans = '1' + ans ;
  cout << ans << "\n" ;
}

int main( void )
{
  Load_Concat() ;
  Sum() ;
}
