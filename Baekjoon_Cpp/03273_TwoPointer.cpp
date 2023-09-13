#include <iostream>
#include <algorithm>
using namespace std ;

int n ;
int* w ;
int ans ;

void Load()
{
  cin >> n ;
  w = new int[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  sort( w , w + n ) ;

  ans = 0 ;
}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
    cout << w[ i ] << " " ;
  cout << "\n" ;
}

// 중간에서 시작하는 것이 아니라
// 양끝에서 시작하는 것이 맞다.
void getPair( int input )
{
  int low = 0 ;
  int high = n - 1 ;
  // cout << low << " , " << high << "\n" ;

  int temp ;
  while( low < high )
  {
    temp = w[ low ] + w[ high ] ;
    if( temp == input )
    {
      ++ans ;
      ++low ;
      --high ;
    }
    else if( temp < input )
      ++low ;
    else
      --high ;
  }
}

int main( void )
{
  Load() ;
  // ShowData() ;

  int input ;
  cin >> input ;
  getPair( input ) ;

  cout << ans << "\n" ;
}
