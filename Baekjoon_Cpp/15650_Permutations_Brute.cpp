#include <iostream>
#include <vector>
using namespace std ;

int n ;
int m ;
vector< int > v ;
int stand ;
bool* visited ;

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

  if( v.empty() )
    stand = 0 ;
  else
    stand = v.back() ;

  for( int i = stand + 1 ; i <= n ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      visited[ i ] = false ;
      v.pop_back() ;
    }
}

void Load()
{
  cin >> n >> m ;
  stand = 0 ;
  visited = new bool[ n + 1 ]{ false } ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  Load() ;
  Permutations( 0 ) ;
}
