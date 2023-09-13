#include <iostream>
using namespace std ;

int** w ;
int n ;
int k ;

void LoadMatrix()
{
  cin >> n >> k ;

  w = new int*[ k + 1 ] ;
  for( int i = 1 ; i <= k ; i++ )
    w[ i ] = new int[ n + 1 ]{ 0 } ;

  for( int i = 1 ; i <= n ; i++ )
    w[ 1 ][ i ] = 1 ;
  for( int i = 1 ; i <= k ; i++ )
    w[ i ][ 1 ] = i ;
}

void ShowData()
{
  for( int i = 1 ; i <= k ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

// DP 식을 세워보니까 ,, 그냥 그렇게 나오던데 ???
// 정확한 원리는 모르겠지만 , 개수 차이가 그렇게 난다,,
// 한 개의 수를 여러 번 써도 된다고 했다.
// ( 3 , 3 ) 3개의 수를 써서 3 표현 : (2+1+0) -> 6개 // (3+0+0)->3개 // (1+1+1)->1개 [ 총 10개 ]
// ( 3 , 2 ) 3개의 수를 써서 2 표현 : (1+1+0) -> 3개 // (2+0+0)->3개 [ 총 6개 ]
// ( 2 , 3 ) 2개의 수를 써서 3 표현 : (3+0+0) -> 3개 // (1+1+1)->1개 [ 총 4개 ]
// w[ i ][ j ] = ( w[ i - 1 ][ j ] + w[ i ][ j - 1 ] ) % 1000000000 ;
void DP()
{
  for( int i = 2 ; i <= k ; i++ )
    for( int j = 2 ; j <= n ; j++ )
      w[ i ][ j ] = ( w[ i - 1 ][ j ] + w[ i ][ j - 1 ] ) % 1000000000 ;
}

int main( void )
{
  LoadMatrix() ;
  DP() ;

  // ShowData() ;
  cout << w[ k ][ n ] % 1000000000 ;
}
