#include <iostream>
using namespace std ;

int n ;
int** w ;
long long** d ;
// long long으로 설정해야 맞았다고 판명남

void LoadMatrix()
{
  cin >> n ;
  w = new int*[ n ] ;
  d = new long long*[ n ] ;

  for( int i = 0 ; i < n ; i++ )
  {
    w[ i ] = new int[ n ] ;
    d[ i ] = new long long[ n ]{ 0 } ;
    for( int j = 0 ; j < n ; j++ )
      cin >> w[ i ][ j ] ;
  }
  d[ 0 ][ 0 ] = 1 ;
}

void ShowData()
{
  cout << "------------------\n" ;
  for( int i = 0 ; i < n ; i++ )
  {
    for( int j = 0 ; j < n ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

void DP()
{
  for( int i = 0 ; i < n ; i++ )
    for( int j = 0 ; j < n ; j++ )
    {
      // 마지막은 0이라 본인에게 값이 더해지므로 찾아가 더하는 과정 없어야 한다.
      if( i == n - 1 && j == n - 1 ) continue ;
      if( i + w[ i ][ j ] < n )
        d[ i + w[ i ][ j ] ][ j ] += d[ i ][ j ] ;
      if( j + w[ i ][ j ] < n )
        d[ i ][ j + w[ i ][ j ] ] += d[ i ][ j ] ;
    }
}

int main( void )
{
  LoadMatrix() ;
  //ShowData() ;

  DP() ;
  //ShowData() ;

  cout << d[ n - 1 ][ n - 1 ] << "\n" ;
}
