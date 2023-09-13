#include <iostream>
#include <vector>
using namespace std ;

int n ;
int** w ;
vector< int > team1 ;
vector< int > team2 ;
int ans ; // 최소 격차

void LoadMatrix()
{
  cin >> n ;
  w = new int*[ n + 1 ] ; // 1 부터 n , 0은 사용하지 않음

  for( int i = 0 ; i <= n ; i++ )
  {
    w[ i ] = new int[ n + 1 ]{ 0 } ;

    if( i )
      for( int j = 1 ; j <= n ; j++ )
        cin >> w[ i ][ j ] ;
  }
  ans = 40000 ; // MAX값 설정
}

int getAbs() // 1부터 n , 0은 사용하지 않음
{
  bool* visited = new bool[ n + 1 ]{ false } ;
  vector< int >::iterator iter ;

  int one = 0 ;
  int two = 0 ;

  int temp ;
  for( iter = team1.begin() ; iter != team1.end() ; ++iter )
    visited[ *iter ] = true ;

  for( int i = 1 ; i <= n ; i++ )
    if( !visited[ i ] )
      team2.push_back( i ) ;
    else // team1 능력치 구한다.
    {
      temp = i ;
      for( int j = 1 ; j <= n ; j++ )
        if( visited[ j ] )
          one += w[ temp ][ j ] ;
    }

  // team2 능력치 구한다.
  for( int i = 1 ; i <= n ; i++ )
    if( !visited[ i ] )
    {
      temp = i ;
      for( int j = 1 ; j <= n ; j++ )
        if( !visited[ j ] )
          two += w[ temp ][ j ] ;
    }
  // cout << "one : " << one <<", two : " << two <<"\n" ;
  return abs( one - two ) ;
}

void Permutations( int cnt ) // 1부터 n , 0은 사용하지 않음
{
  if( cnt == n / 2 )
  {
    int result = getAbs() ;
    if( result < ans ) ans = result ;
    return ;
  }

  int top ;
  if( !team1.size() ) top = 0 ;
  else top = team1.back() ;

  for( int i = top + 1 ; i <= n ; i++ )
  {
    team1.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    team1.pop_back() ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  LoadMatrix() ;
  Permutations( 0 ) ;
  cout << ans << "\n" ;
}
