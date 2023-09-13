#include <iostream>
using namespace std ;

// modulo 연산 필요
// https://nanyoungkim.tistory.com/115

void find( int n ) ;
int getLen( long long in ) ;

int main( void )
{
  int n ;
  int k ;
  int comp ;
  while( cin >> n ) // 입력의 개수가 없을 때
  {
    k = 1 ;
    comp = 1 ;
    while( comp %= n )
    {
      k++ ;
      comp = comp * 10 + 1 ;
      comp %= n ;
    }
    cout << k << "\n" ;
  }
}
