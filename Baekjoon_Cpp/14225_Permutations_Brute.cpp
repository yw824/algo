#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int n ; // 크기
vector< int > v ;
bool* d ; // 나올 수 있는 수 체크
int* w ; // 원소 담는 배열
bool* visited ; // 원소 방문 여부 체크
int MAX ;

void Load()
{
  cin >> n ;
  MAX = 0 ;


  w = new int[ n ] ;
  visited = new bool[ n ]{ false } ;
  for( int i = 0 ; i < n ; i++ )
  {
    cin >> w[ i ] ;
    MAX += w[ i ] ;
  }
  d = new bool[ ++MAX ]{ false } ;

  sort( w , w + n ) ;
}

int Check()
{
  int ans = 0 ;
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    ans += w[ *iter ] ;
  return ans ;
}

void Permutations( int cnt )
{
  d[ Check() ] = true ;

  int top ; // 벡터 최상위 인덱스
  if( !v.size() ) top = -1 ;
  else top = v.back() ;

  for( int i = top + 1 ; i < n ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      v.pop_back() ;
      visited[ i ] = false ;
    }
}

void getMin()
{
  int index = 1 ;
  while( 1 )
  {
    if( !d[ index ] )
    {
      cout << index << "\n" ;
      return ;
    }
    ++index ;
  }
}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
    cout << w[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  Load() ;
  // ShowData() ;

  Permutations( 0 ) ;
  getMin() ;
}
