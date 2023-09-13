#include <iostream>
#include <cmath>
using namespace std ;

int limit ;
bool* prime ;

void PrimeSet( int i ) ;
void set() ;
void unset() ;

int main( void )
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  // 이거 없으면 시간초과 뜬다.

  set() ;
  int n = 0 ;
  bool status = false ;

  while( 1 )
  {
    status = false ;
    cin >> n ;
    if( !n ) break ;

    for( int i = 3 ; i <= n / 2 ; i += 2 )
    {
      if( !prime[ i ] && !prime[ n - i ] )
      {
        cout << n << " = " << i << " + " << n - i << '\n';
        status = true ;
        break ;
      }
    }

    if( !status )
      cout << "Goldbach's conjecture is wrong.\n" ;
  }

  unset() ; // prime 배열 메모리 해제
}

void set() // 초기값, 메모리 설정 및 소수 배열 설정
{
  limit = 1000000 ;
  prime = new bool[ limit + 1 ]{ false } ;
  for( int i = 2 ; i <= (int)sqrt( limit ) ; i++ )
    if( !prime[ i ] )
      PrimeSet( i ) ;
}

void PrimeSet( int i ) // 소수 구하기 - 에라토스테네스의 체
{
  int count = 2 ;
  while( count * i <= limit )
  {
    prime[ count * i ] = true ;
    ++count ;
  }
}

void unset() // prime 배열 메모리 해제
{
  delete[] prime ;
}
