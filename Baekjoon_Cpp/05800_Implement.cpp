#include <iostream>
#include <algorithm>
using namespace std ;

int n ;
int** w ;
int* Size ;

void Load()
{
  cin >> n ;
  w = new int*[ n ] ;
  Size = new int[ n ] ;

  int Max , Min , gap ;
  for( int i = 0 ; i < n ; i++ )
  {
    Max = -1 , Min = 101 , gap = 0 ;
    cin >> Size[ i ] ;
    w[ i ] = new int[ Size[ i ] ] ;
    for( int j = 0 ; j < Size[ i ] ; j++ )
    {
      cin >> w[ i ][ j ] ;
      if( w[ i ][ j ] > Max ) Max = w[ i ][ j ] ;
      if( w[ i ][ j ] < Min ) Min = w[ i ][ j ] ;
    }
    sort( w[i] , w[i] + Size[ i ] ) ;
    for( int j = 1 ; j < Size[ i ] ; j++ )
      if( abs( w[ i ][ j ] - w[ i ][ j - 1 ] ) > gap )
        gap = abs( w[ i ][ j ] - w[ i ][ j - 1 ] ) ;
    printf( "Class %d\n" , i + 1 ) ;
    printf( "Max %d, Min %d, Largest gap %d\n", Max , Min , gap ) ;
  }
}
int main( void )
{
  Load() ;
}
