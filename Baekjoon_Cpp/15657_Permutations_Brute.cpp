#include <iostream>
#include <vector>
using namespace std ;

int n ;
int m ;
int* w ;
int stand ;
vector< int > v ;

void MergeTwoArea( int left , int middle , int right )
{
  int sIdx = 0 , lIdx = left , rIdx = middle + 1 ;
  int* temp = new int[ right - left + 1 ] ;

  while( lIdx <= middle && rIdx <= right )
  {
    if( w[ lIdx ] < w[ rIdx ] )
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
  cin >> n >> m ;

  w = new int[ n + 1 ]{ 0 } ;
  for( int i = 1 ; i <= n ; i++ )
    cin >> w[ i ] ;

  MergeSort( 1, n ) ;
  stand = 0 ;
}

void Print()
{
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << w[ *iter ] << " " ;
  cout << "\n" ;
}

void Permutations( int cnt )
{
  if( cnt == m )
  {
    Print() ;
    return ;
  }

  if( v.empty() )
    stand = 1 ;
  else
    stand = v.back() ;

  for( int i = stand ; i <= n ; i++ )
  {
    v.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    v.pop_back() ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  Load() ;
  Permutations( 0 ) ;
}
