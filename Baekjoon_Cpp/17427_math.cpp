#include <iostream>
using namespace std ;

int* w ;
int n ;
long long g_n ;

void init() ;

void Load()
{
  cin >> n ;

  w = new int[ n + 1 ]{ 0 } ;
  g_n = 0 ;

  init() ;

  for( int i = 1 ; i <= n ; i++ )
    g_n += w[ i ] ;
  cout << g_n << "\n" ;

  delete[] w ;
}

void init() // i는 i의 배수에 모두 더해주기
{
  int index ;
  for( int i = 1 ; i <= n ; i++ )
  {
    index = i ;
    for( int j = index ; j <= n ; j += index )
      w[ j ] += index ;
  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << i << " : " << w[ i ] << "\n" ;
}

int main( void )
{
  Load() ;
  // ShowData() ;
}
