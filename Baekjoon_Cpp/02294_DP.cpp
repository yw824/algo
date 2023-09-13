#include <iostream>
using namespace std ;

int n ; // 사용 가능한 동전 종류
int k ; // 만들고 싶은 k원
int* w ; // 동전 종류 배열
int* d ; // k까지의 dp 배열

#define MAX 20000000

void Load()
{
  cin >> n >> k ;

  w = new int[ n ] ;
  d = new int[ k + 1 ]{ 0 } ;

  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  for( int i = 1 ; i <= k ; i++ )
    d[ i ] = MAX ;
}

void DP()
{
  for( int i = 0 ; i < n ; i++ )
  {
    d[ w[ i ] ] = 1 ;
    for( int j = w[ i ] + 1 ; j <= k ; j++ )
      if( d[ j ] > d[ j - w[ i ] ] + 1 ) // 만약 j부분이 j - i + 1보다 크다면
        d[ j ] = d[ j - w[ i ] ] + 1 ; // j - i 에서 i번쨰 동전을 하나 더한 것이 더 개수가 갖다.
  }
}

void ShowData()
{
  for( int i = 0 ; i <= k ; i++ )
    cout << d[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  Load() ;
  DP() ;
  // ShowData() ;
  if( d[ k ] == MAX )
    cout << "-1\n" ;
  else
    cout << d[ k ] << "\n" ;
}
