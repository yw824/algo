#include <iostream>
#include <algorithm>
using namespace std ;

// DFS

long long a , b ;
int mini = 10000 ; // 임의의 큰 수

void DFS( long long a , int cnt )
{
  if( a > b ) return ;
  if( a == b )
  {
    mini = min( mini , cnt ) ;
  }
  DFS( a * 2 , cnt + 1 ) ;
  DFS( a * 10 + 1 , cnt + 1 ) ;
}

int main( void )
{
  cin >> a >> b ;

  DFS( a , 1 ) ;
  if( mini == 10000 ) cout << "-1" ;
  else cout << mini ;
}
