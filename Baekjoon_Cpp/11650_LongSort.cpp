#include <iostream>
using namespace std ;

int n ;
int* x ;
int* y ;

void MergeTwoArea( int left , int middle , int right )
{
  int sIdx = 0 , lIdx = left , rIdx = middle + 1 ;
  int* xtmp = new int[ right - left + 1 ] ;
  int* ytmp = new int[ right - left + 1 ] ;

  while( lIdx <= middle && rIdx <= right )
  {
    if( ( x[ lIdx ] < x[ rIdx ] ) || ( ( x[ lIdx ] == x[ rIdx ] ) && ( y[ lIdx ] < y[ rIdx ] ) ) )
    {
      xtmp[ sIdx ] = x[ lIdx ] ;
      ytmp[ sIdx++ ] = y[ lIdx++ ] ;
    }
    else
    {
      xtmp[ sIdx ] = x[ rIdx ] ;
      ytmp[ sIdx++ ] = y[ rIdx++ ] ;
    }
  }

  while( lIdx <= middle )
  {
    xtmp[ sIdx ] = x[ lIdx ] ;
    ytmp[ sIdx++ ] = y[ lIdx++ ] ;
  }
  while( rIdx <= right )
  {
    xtmp[ sIdx ] = x[ rIdx ] ;
    ytmp[ sIdx++ ] = y[ rIdx++ ] ;
  }
  for( int i = left ; i <= right ; i++ )
  {
    x[ i ] = xtmp[ i - left ] ;
    y[ i ] = ytmp[ i - left ] ;
  }
  delete[] xtmp ;
  delete[] ytmp ;
}

void MergeSort( int left , int right )
{
  if( left < right )
  {
    int middle = ( left + right ) / 2 ;
    MergeSort( left , middle ) ;
    MergeSort( middle + 1 , right ) ;
    MergeTwoArea( left , middle , right ) ;
  }
}

void Load()
{
  cin >> n ;
  x = new int[ n ] ;
  y = new int[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    cin >> x[ i ] >> y[ i ] ;
  MergeSort( 0 , n - 1 ) ;
}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
    cout << x[ i ] << " " << y[ i ] << "\n" ;
}

int main( void )
{
  Load() ;
  ShowData() ;
}
