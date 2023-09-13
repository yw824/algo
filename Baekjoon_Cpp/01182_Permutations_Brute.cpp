#include <iostream>
#include <vector>
using namespace std ;

vector< int > v ;
int n ;
int* w ; // 배 // 개수 n
bool* visited ;
int standard ; // 합이 S
int limit ; // 최대 개수
int count ; // s가 되는 조합 개수

void Load()
{
  cin >> n >> standard ;
  w = new int[ n ]{ 0 } ;
  visited = new bool[ n ]{ false } ;

  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  count = 0 ;
}

void Set()
{
  while( !v.empty() )
    v.pop_back() ;

  for( int i = 0 ; i < n ; i++ )
    visited[ i ] = false ;
}

bool isSubSet()
{
  int ans = 0 ;
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    ans += w[ *iter ] ;

  return ( ans == standard ? true : false ) ;
}

void Permutations( int cnt )
{
  if( limit == cnt )
  {
    if( isSubSet() )
      count++ ;
    return ;
  }

  int front ;
  if( v.empty() )
    front = -1 ;
  else
    front = v.back() ;

  for( int i = front + 1 ; i < n ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      v.pop_back() ;
      visited[ i ] = false ;
    }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  Load() ;
  for( int i = 1 ; i <= n ; i++ )
  {
    Set() ;
    limit = i ;
    Permutations( 0 ) ;
  }
  cout << count << "\n" ;
}
