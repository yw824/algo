#include <iostream>
using namespace std ;

int test ;
int** w ;
int n ;
int m ;
int k ;
int count ;

void LoadMatrix()
{
  cin >> n >> m >> k ;
  w = new int*[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    w[ i ] = new int[ m ]{ 0 } ;
  while( k-- )
  {
    int x , y ;
    cin >> x >> y ;
    w[ x ][ y ] = 1 ;
  }
  count = 0 ;
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

void DFS( int i , int j )
{
  w[ i ][ j ] = 2 ;
  if( i - 1 >= 0 )
    if( w[ i - 1 ][ j ] == 1 )
      DFS( i - 1 , j ) ;
  if( i + 1 < n )
    if( w[ i + 1 ][ j ] == 1 )
      DFS( i + 1 , j ) ;
  if( j - 1 >= 0 )
    if( w[ i ][ j - 1 ] == 1 )
      DFS( i , j - 1 ) ;
  if( j + 1 < m )
    if( w[ i ][ j + 1 ] == 1 )
      DFS( i , j + 1 ) ;
}

void Clear()
{
  for( int i = 0 ; i < n ; i++ )
    delete[] w[ i ] ;
  delete[] w ;
}

int main( void )
{
  cin >> test ;
  while( test-- )
  {
    LoadMatrix() ;
    //ShowData() ;
    for( int i = 0 ; i < n ; i++ )
      for( int j = 0 ; j < m ; j++ )
        if( w[ i ][ j ] == 1 )
        {
          count += 1 ;
          DFS( i , j ) ;
        }
    cout << count << "\n" ;
    Clear() ;
  }
}
