#include <iostream>
using namespace std ;

int* w ;
int n ;

// #include <algorithm> 으로 그냥 빠르게 정렬하는 게 빠르다.
// MergeSort는 계속 동적 할당을 해야 해서 메모리를 많이 차지한다.

void MergeTwoArea( int left , int middle , int right )
{
  int lIdx = left , rIdx = middle + 1 , sIdx = 0 ;
  int* temp = new int[ right - left + 1 ] ;

  while( lIdx <= middle && rIdx <= right )
  {
    if( w[ lIdx ] > w[ rIdx ] )
      temp[ sIdx++ ] = w[ lIdx++ ] ;
    else
      temp[ sIdx++ ] = w[ rIdx++ ] ;
  }

  while( lIdx <= middle )
    temp[ sIdx++ ] = w[ lIdx++ ] ;
  while( rIdx <= right )
    temp[ sIdx++ ] = w[ rIdx++ ] ;


  for( int i = left ; i <= right ; i++ )
    w[ i ] = temp[ i - left ] ;

  delete[] temp ;
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
  w = new int[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  MergeSort( 0 , n - 1 ) ;
}

void Unload()
{
  delete[] w ;
}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
    cout << w[ i ] << "\n" ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  Load() ;
  ShowData() ;
  Unload() ;
}
