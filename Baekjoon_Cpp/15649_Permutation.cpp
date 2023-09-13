#include <iostream>
#include <vector>
using namespace std ;

// https://yabmoons.tistory.com/100

vector< int > v ;
int n ; // from n-amount digit
int m ; // select m
bool* d ; // visited

void Print()
{
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << *iter << " " ;
  cout << "\n" ;
}

void Load()
{
  cin >> n >> m ;
  d = new bool[ n + 1 ]{ false } ;
}

void Permutation( int cnt ) // cnt : 누적 선택한 개수
{
  if( cnt == m ) // 원하는 개수 도달하면 출력
  {
    Print() ;
    return ;
  }
  for( int i = 1 ; i <= n ; i++ ) // 포함된 거 제외하고, 그 다음 포함안된거 포함시키기
  {
    if( d[ i ] ) continue ;
    d[ i ] = true ;
    v.push_back( i ) ;
    Permutation( cnt + 1 ) ; // 항목 하나 더 추가 + DFS
    v.pop_back() ;
    d[ i ] = false ;
  }
}

int main( void )
{
  Load() ;
  Permutation( 0 ) ;
}
