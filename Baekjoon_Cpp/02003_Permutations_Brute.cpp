#include <iostream>
#include <vector>
using namespace std ;

long long* w ;
vector< int > v ;
int n ; // n개의 수로 된 수열
long long m ; // m이 되는 경우의 수
int ans ;

void Load()
{
  cin >> n >> m ;
  w = new long long[ n + 1 ]{ 0 } ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> w[ i ] ;
    w[ i ] += w[ i - 1 ] ; // 누적 합
  }
  ans = 0 ;
}

void Check()
{
  if( m == w[ v.back() ] - w[ v.front() ] )
  {
    // cout << v.front() << " , " << v.back() << "\n" ;
    ans += 1 ;
  }
}

void Permutations( int cnt )
{
  if( cnt == 2 )
  {
    Check() ;
    return ;
  }
  int stand ;
  if( v.size() ) stand = v.back() ;
  else stand = 0 ;
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
  cout << ans << "\n" ;
}
