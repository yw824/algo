#include <iostream>
using namespace std;

int n ;
int* a ;
int* b ;

// Greedy Algorithm - 시간표 정렬

// 배열 A와 배열 B 둘 다 한번에 정렬
void MergeTwoArea( int left , int middle , int right )
{
  int sIdx = 0 , lIdx = left , rIdx = middle + 1 ;
  int* temp = new int[ n ] ;
  while ( lIdx <= middle && rIdx <= right )
  {
    if(a[ lIdx ] < a[ rIdx ] )
      temp[ sIdx++ ] = a[ lIdx++ ] ;
    else
      temp[ sIdx++ ] = a[ rIdx++ ] ;
  }
  while ( lIdx <= middle )
    temp[ sIdx++ ] = a[ lIdx++ ] ;
  while ( rIdx <= right )
    temp[ sIdx++ ] = a[ rIdx++ ] ;
  for(int i = left ; i <= right ; i++ )
    a[ i ] = temp[ i - left ] ;

  sIdx=0 ; lIdx = left ; rIdx = middle + 1 ;
  while ( lIdx <= middle && rIdx <= right )
  {
    if(b[ lIdx ] < b[ rIdx ] )
      temp[ sIdx++ ] = b[ lIdx++ ] ;
    else
      temp[ sIdx++ ] = b[ rIdx++ ] ;
  }
  while ( lIdx <= middle )
    temp[ sIdx++ ] = b[ lIdx++ ] ;
  while ( rIdx <= right )
    temp[ sIdx++ ] = b[ rIdx++ ] ;
  for(int i = left ; i <= right ; i++ )
    b[ i ] = temp[ i - left ] ;

  delete temp;
}


void MergeSort( int left , int right )
{
  if ( left < right )
  {
    int middle = ( left + right ) / 2 ;
    MergeSort( left , middle ) ;
    MergeSort( middle + 1 , right ) ;
    MergeTwoArea( left , middle , right ) ;
  }
}

int main(void)
{
  cin >> n ;

  a = new int [ n ] ;
  b = new int [ n ] ;

  for ( int i = 0 ; i < n ; i++ )
    cin >> a[ i ] ;

  for ( int i = 0 ; i < n ; i++ )
    cin >> b[ i ] ;

  MergeSort( 0 , n-1 ) ;

  int result = 0 ;

  for ( int i = 0 ; i < n ; i++ )
    result += a[i] * b[ n - i - 1 ] ;

  printf("%d\n" , result ) ;

}
