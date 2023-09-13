#include <iostream>
#include <utility>
using namespace std ;

int n ;
pair< int , int >* p ;
int ans ;

void Load()
{
  cin >> n ;
  p = new pair< int , int >[ n + 1 ] ;
  p[ 0 ].first = 2 ; p[ 0 ].second = 0 ;

  int fir, sec ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> fir >> sec ;
    p[ i ].first = fir ;
    p[ i ].second = sec ;
  }

  ans = 0 ;
}

void Sol( int i , int total )
{
  if( total > ans ) ans = total ;
  if( i == n ) return ;
  if( i + p[ i ].first <= n )
    Sol( i + p[ i ].first , total + p[ i ].second ) ;
  if( i + 1 <= n )
    Sol( i + 1 , total ) ;
}

int main( void )
{
  Load() ;
  Sol( 0 , 0 ) ;
  cout << ans << "\n" ;
}
