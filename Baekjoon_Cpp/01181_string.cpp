#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std ;

// 중복 제거
// https://keelim.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
// -cpp-vector-%EC%A4%91%EB%B3%B5-%EC%A0%9C%EA%B1%B0-%EB%B0%A9%EB%B2%95

vector< string > vc ;

void MergeTwoArea( int left , int middle , int right )
{
  vector< string > v ;
  int lIdx = left ; int rIdx = middle + 1 ;

  long int llen , rlen ;
  while( lIdx <= middle && rIdx <= right )
  {
    llen = vc[ lIdx ].length() ;
    rlen = vc[ rIdx ].length() ;
    if( llen < rlen || ( llen == rlen && vc[ lIdx ].compare( vc[ rIdx ] ) < 0 ) )
      v.push_back( vc[ lIdx++ ] ) ;
    else
      v.push_back( vc[ rIdx++ ] ) ;
  }
  while( lIdx <= middle )
    v.push_back( vc[ lIdx++ ] ) ;
  while( rIdx <= right )
    v.push_back( vc[ rIdx++ ] ) ;

  for( int i = left ; i <= right ; i++ )
    vc[ i ] = v[ i - left ] ;
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

int main( void )
{
    cin.tie(0), ios::sync_with_stdio(0);

    int n ;
    cin >> n ;

    string str ;
    while( n-- )
    {
      cin >> str ;
      vc.push_back( str ) ;
    }
    sort( vc.begin(), vc.end() ) ;
    vc.erase( unique( vc.begin() , vc.end() ) , vc.end() ) ;

    long int size = vc.size() ;
    MergeSort( 0 , vc.size() - 1 ) ;

    for( int i = 0 ; i < vc.size() ; i++ )
      cout << vc[ i ] << "\n" ;
}
