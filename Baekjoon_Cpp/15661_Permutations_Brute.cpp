#include <iostream>
#include <vector>
using namespace std ;

int n ;
int** w ;
vector< int > team1 ;
int ans ;

void LoadMatrix()
{
  ans = 0 ;

  cin >> n ;
  w = new int*[ n ] ;
  for( int i = 0 ; i < n ; i++ )
  {
    w[ i ] = new int[ n ]{ 0 } ;
    for( int j = 0 ; j < n ; j++ )
    {
      cin >> w[ i ][ j ] ;
      ans += w[ i ][ j ] ;
    }
  }
}

void Evaluate()
{
  int one = 0 , two = 0 ; // team1 케미 , team2 케미
  bool* visited = new bool[ n ]{ false } ;

  vector< int >::iterator iter ;
  for( iter = team1.begin() ; iter != team1.end() ; ++iter )
  {
    visited[ *iter ] = true ;
    // cout << *iter << " " ;
  }
  // cout << "\n" ;

  for( int i = 0 ; i < n ; i++ )
  {
    if( visited[ i ] ) // team1에 있으면
    {
      for( int j = 0 ; j < n ; j++ )
        if( visited[ j ] ) // i , j 모두 team1에 있으면 team1 케미에 더하기
        {
          one += w[ i ][ j ] ;
          // cout << " team1[ " << i << " ][ " << j << " ] : " << w[ i ][ j ] << "\n" ;
        }
    }
  }

  for( int i = 0 ; i < n ; i++ )
  {
    if( !visited[ i ] )
    {
      for( int j = 0 ; j < n ; j++ )
        if( !visited[ j ] )
        {
          two += w[ i ][ j ] ;
          // cout << " team2[ " << i << " ][ " << j << " ] : " << w[ i ][ j ] << "\n" ;
        }
    }
  }

  // cout << " // one : " << one << " , two : " << two << " \n" ;

  int result = abs( one - two ) ;
  if( ans > result ) ans = result ;

  // cout << "------------------------------------------\n" ;
}

void Permutations( int cnt )
{
  if( cnt > 0 && cnt < n ) // 최소 1명은 팀에 있어야 함
  {
    Evaluate() ;
  }
  else if( cnt == n )
    return ;

  int stand ;
  if( !team1.size() ) stand = -1 ;
  else stand = team1.back() ;

  for( int i = stand + 1 ; i < n ; i++ )
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
