#include <iostream>
#include <string>
using namespace std ;

int n ;
int m ;
int** w ;
int** d ;

void LoadMatrix()
{
  cin >> n >> m ;

  w = new int*[ n ] ;
  d = new int*[ n ] ;

  for( int i = 0 ; i < n ; i++ )
  {
    w[ i ] = new int[ m ] ;
    d[ i ] = new int[ m ] ;

    string str ;
    cin >> str ;
    for( int j = 0 ; j < str.length() ; j++ )
    {
      d[ i ][ j ] = 9999999 ;
      w[ i ][ j ] = str[ j ] - 48 ;
    }
  }
}

void DFS( int i , int j , int count )
{

  if( d[ i ][ j ] <= count ) return ;
  d[ i ][ j ] = count ;

  // printf( "i : %d , j : %d , count : %d\n" , i , j , count ) ;

  // w[ x - 1 ][ y - 1 ]
  if( i - 1 >= 0 )
    if( w[ i - 1 ][ j ] )
      DFS( i - 1 , j , count + 1 ) ;
  if( i + 1 < n )
    if( w[ i + 1 ][ j ] )
      DFS( i + 1 , j , count + 1 ) ;
  if( j - 1 >= 0 )
    if( w[ i ][ j - 1 ] )
      DFS( i , j - 1 , count + 1 ) ;
  if( j + 1 < m )
    if( w[ i ][ j + 1 ] )
      DFS( i , j + 1 , count + 1 ) ;
}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
  {
    for( int j = 0 ; j < m ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  LoadMatrix() ;
  // ShowData() ;

  DFS( 0 , 0 , 1 ) ;
  cout << d[ n - 1 ][ m - 1 ] ;
}
