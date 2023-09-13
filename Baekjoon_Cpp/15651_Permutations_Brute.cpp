#include <iostream>
#include <vector>
using namespace std ;

int n ;
int m ;
vector< int > v ;

void Print()
{
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << *iter << " " ;
  cout << "\n" ;
}

void Permutations( int cnt )
{
  if( cnt == m )
  {
    Print() ;
    return ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    v.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    v.pop_back() ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m ;
  Permutations( 0 ) ;
}
