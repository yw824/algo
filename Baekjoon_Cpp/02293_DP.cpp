#include <iostream>
using namespace std ;

int n ; // 동전 개수
int k ; // 총합 k원

int* w ; // 동전들
int* d ; // dp 배열

void LoadMatrix()
{
  cin >> n >> k ;
  w = new int[ n ] ;
  d = new int[ k + 1 ]{ 0 } ;

  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;
}

void DP()
{
  for( int i = 0 ; i < n ; i++ )
  {
    d[ w[ i ] ] += 1 ;
    for( int j = w[ i ] + 1 ; j <= k ; j++ )
      d[ j ] += d[ j - w[ i ] ] ;
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
  LoadMatrix() ;
  //ShowData() ;
  DP() ;
  //ShowData() ;
  cout << d[ k ] << "\n" ;
}
