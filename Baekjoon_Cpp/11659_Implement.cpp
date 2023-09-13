#include <iostream>
using namespace std ;

int n ;
int* w ;
int order ;

void Load()
{
  cin >> n >> order ;
  w = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> w[ i ] ;
    w[ i ] += w[ i - 1 ] ;
  }
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
    cout << w[ i ] << " " ;
  cout << "\n" ;
}

void Accu_Sum()
{
  int start , end ;
  while( order-- )
  {
    cin >> start >> end ;
    cout << w[ end ] - w[ start - 1 ] << "\n" ;
  }
}

int main( void )
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Load() ;
  // ShowData() ;
  Accu_Sum() ;
}
