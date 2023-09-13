#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int n ;
vector< int > v ;
int Count ;

void Load()
{
  cin >> n ;

  int temp ;
  for( int i = 0 ; i < n ; i++ )
  {
    cin >> temp ;
    v.push_back( temp ) ;
  }

  sort( v.begin() , v.end() ) ;

  Count = 0 ;
}

void ShowData()
{
  vector< int >::iterator iter ;

  for( vector< int >::iterator iter = v.begin() ; iter != v.end() ; ++iter )
    cout << *iter << " " ;
  cout << "\n" ;
}

void Permutations()
{
  int temp ;

  do {
    temp = 0 ;
    for( int i = 0 ; i < n - 1 ; i++ )
      temp += abs( v[ i ] - v[ i + 1 ] ) ;

    if( temp > Count )
      Count = temp ;
  } while( next_permutation(v.begin(), v.end()) ) ;
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  Load() ;
  // ShowData() ;
  Permutations() ;
  cout << Count << "\n" ;
}
