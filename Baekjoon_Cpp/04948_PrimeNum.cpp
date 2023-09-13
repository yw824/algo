#include <iostream>
#include <cmath>
#include <vector>
using namespace std ;

// 소수
// Memoization 수행

int Max ;
vector< int > v ;
bool* d ; // 배열

// 초기 설정
void Load()
{
  int input ;
  Max = 0 ;
  while( true )
  {
    cin >> input ;
    if( !input ) break ;
    v.push_back( input ) ;
    if( Max < input ) Max = input ;
  }

  // 최대 구해야 하는 입력된 수
  d = new bool[ 2 * Max + 1 ]{ 0 } ;
  d[ 1 ] = true ; // 1은 소수가 아니므로 1 설정
}

// 소수 판별
void Prime()
{
  // 1은 소수가 아니므로 2부터 시작
  for( int i = 2 ; i <= sqrt( 2 * Max ) ; i++ )
  {
    // i가 소수가 아닐 경우에 넘어가기
    if( d[ i ] ) continue ;

    // 아래 내용 : 만약 소수일 경우에

    // 해당 소수로 해당 수보다 큰 수들을 나눠본다.
    for( int j = 2 ; i * j <= 2 * Max ; j++ )
      d[ i * j ] = true ;
  }
}

int count( int index )
{
  int ans = 0 ;
  for( int i = index + 1 ; i <= 2 * index ; i++ )
    if( !d[ i ] )
      ++ans ;
  return ans ;
}

int main( void )
{
  Load() ;
  Prime() ;

  for( vector< int >::iterator iter = v.begin() ; iter != v.end() ; ++iter )
    cout << count( *iter ) << "\n" ;
}
