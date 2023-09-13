#include <iostream>
using namespace std ;

int row ;
int col ;
int** w ;
int** d ;
int count ;

int* dx = new int[8]{ -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 } ;
int* dy = new int[8]{ -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 } ;

void Load()
{
  w = new int*[ row + 2 ] ;
  d = new int*[ row + 2 ] ;

  for( int i = 0 ; i <= row + 1 ; i++ )
  {
    w[ i ] = new int[ col + 2 ]{ 0 } ;
    d[ i ] = new int[ col + 2 ]{ 0 } ;

    if( i && i <= row )
      for( int j = 1 ; j <= col ; j++ )
        cin >> w[ i ][ j ] ;
  }
  count = 0 ;
}

void DFS( int i , int j )
{
  d[ i ][ j ] = 1 ;

  for( int k = 0 ; k < 8 ; k++ )
    if( !d[ i + dx[ k ] ][ j + dy[ k ] ] && w[ i + dx[ k ] ][ j + dy[ k ] ] )
      DFS( i + dx[ k ] , j + dy[ k ] ) ;

}

void Clear()
{
  for( int i = 0 ; i <= row + 1  ; i++ )
  {
    delete[] w[ i ] ;
    delete[] d[ i ] ;
  }
  delete[] w ;
  delete[] d ;
}

int main( void )
{
  while( true )
  {
    cin >> col >> row ;
    if( !( col + row ) ) break ;
    Load() ;

    for( int i = 1 ; i <= row ; i++ )
      for( int j = 1 ; j <= col ; j++ )
      {
        if( !d[ i ][ j ] && w[ i ][ j ] )
        {
          ++count ;
          DFS( i , j ) ;
        }
      }
    cout << count << "\n" ;
    Clear() ;
  }
}
