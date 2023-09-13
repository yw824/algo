#include <iostream>
#include <vector>
using namespace std ;

int n ;
int m ;
vector< int > v ;
int stand ;

void Print()
{
  vector<int>::iterator iter ;
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
    stand = 1 ;
  else
    stand = v.back() ;

  for( int i = stand ; i <= n ; i++ )
  {
    v.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    v.pop_back() ;
  }
}

int main( void )
{
  cin >> n >> m ;
  stand = 0 ;
  Permutations( 0 ) ;
}
