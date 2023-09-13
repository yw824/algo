#include <iostream>
#include <vector>
using namespace std ;

int n ; // 아이스크림 종류
int m ; // 금지된 조합 수
bool** w ; // 조합 행렬 - 1부터 n까지
int ans ; // 가능한 조합의 수
vector< int > v ;

void LoadMatrix()
{
  cin >> n >> m ;
  w = new bool*[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
    w[ i ] = new bool[ n + 1 ]{ false } ;

  int x1 , x2 ;
  while( m-- )
  {
    cin >> x1 >> x2 ;
    w[ x1 ][ x2 ] = true ;
    w[ x2 ][ x1 ] = true ;
  }

  ans = 0 ;
}

// 3가지 선택
void Permutations( int cnt )
{
  if( cnt == 3 )
  {
    ++ans ;
    return ;
  }
  int stand ;
  if( !v.size() ) stand = 0 ;
  else stand = v.back() ;

  bool status ;
  vector< int >::iterator iter ;
  for( int i = stand + 1 ; i <= n ; i++ )
  {
    status = false ; // 금지된 조합이 있는지 지표
    for( iter = v.begin() ; iter != v.end() ; ++iter )
      if( w[ *iter ][ i ] ) // 만약 새로운 것이 들어갔을 때 금지된 조합이라면
      {
        status = true ; // 금지된 조합이 있다고 판단
        break ;
      }
    if( status ) // 넘기기
      continue ;

    // 새로운 것을 넣어도 금지된 조합이 아니라면 넣기
    v.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    v.pop_back() ;
  }
}

int main( void )
{
  LoadMatrix() ;
  Permutations( 0 ) ;
  cout << ans << "\n" ;
}
