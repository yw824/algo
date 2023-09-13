#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

queue< int > subin ;
int bro ;
queue< int > step ;
int ans ;
bool check[ 100001 ] ;

void Load()
{
  int subintemp ;
  cin >> subintemp >> bro ;

  subin.push( subintemp ) ;
  step.push( 0 ) ;
  ans = abs( subintemp - bro ) ;
  // cout << "init step : " << ans << "\n" ;
  for( int i = 0 ; i <= 100000 ; i++ )
    check[ i ] = false ;
}

void BFS()
{
  int subincurr ;
  int stepcurr ;
  while( 1 )
  {
    subincurr = subin.front() ;
    stepcurr = step.front() ;
    subin.pop() ;
    step.pop() ;

    check[ subincurr ] = true ;

    // cout << "current subin : " << subincurr << "\n" ;

    if( subincurr - bro == 0 )
    {
        ans = stepcurr ;
        return ;
    }

    if( subincurr - 1 >= 0 && !check[ subincurr - 1 ] )
    {
      subin.push( subincurr - 1 ) ;
      step.push( stepcurr + 1 ) ;
    }
    if( subincurr + 1 <= 100000 && !check[ subincurr + 1 ] )
    {
      subin.push( subincurr + 1 ) ;
      step.push( stepcurr + 1 ) ;
    }
    if( subincurr * 2 <= 100000 && !check[ subincurr * 2 ] )
    {
      subin.push( subincurr * 2 ) ;
      step.push( stepcurr + 1 ) ;
    }
  }
}

int main( void )
{
  Load() ;
  BFS() ;
  cout << ans << "\n" ;
}
