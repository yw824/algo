#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

vector< int > v ;
vector< int > c ;
int* w ;
bool* visited ;
int stand ;
bool status ;

void Load()
{
  w = new int[ 10 ]{ 0 } ;
  visited = new bool[ 10 ]{ false } ;
  for( int i = 1 ; i <= 9 ; i++ )
    cin >> w[ i ] ;
  status = false ;
}

void Evaluate()
{
  int ans = 0 ;
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    ans += w[ *iter ] ;

  if( ans == 100 && !status )
  {
    status = true ;
    for( int i = 0 ; i < v.size() ; i++ )
      c.push_back( w[ v[ i ] ] ) ;

    sort( c.begin() , c.end() ) ;

    for( iter = c.begin() ; iter != c.end() ; ++iter )
      cout << *iter << "\n" ;
  }
}

void Permutations( int cnt )
{
  if( cnt == 7 )
  {
    Evaluate() ;
    return ;
  }

  if( !v.size() )
    stand = 0 ;
  else
    stand = v.back() ;

  int i ;
  for( i = stand + 1 ; i <= 9 ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      visited[ i ] = false ;
      v.pop_back() ;
    }
}

int main( void )
{
  Load() ;
  Permutations( 0 ) ;
}
