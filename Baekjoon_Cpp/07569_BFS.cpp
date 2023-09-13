#include <iostream>
#include <utility>
#include <queue>
using namespace std ;

int r ;
int c ;
int** w ;
queue< pair< int , int > > q ;
int count ;

void LoadMatrix()
{
  cin >> c >> r ;
  w = new int*[ r + 2 ] ;
  count = 0 ;

  for( int i = 0 ; i <= r + 1 ; i++ )
  {
    w[ i ] = new int[ c + 2 ] ;
    for( int j = 0 ; j <= c + 1 ; j++ )
      w[ i ][ j ] = -1 ;
    if( !i || i == r + 1 ) continue ;
    for( int j = 1 ; j <= c ; j++ )
    {
      cin >> w[ i ][ j ] ;
      if( w[ i ][ j ] == 1 )
        q.push( make_pair( i , j ) ) ;
    }
  }
  count = 0 ;
}

void ShowData()
{
  for( int i = 1 ; i <= r ; i++ )
  {
    for( int j = 1 ; j <= c ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}


void BFS()
{
  while( !q.empty() )
  {
    if( w[ q.front().first ][ q.front().second ] > count ) count = w[ q.front().first ][ q.front().second ] ;

    if( !w[ q.front().first - 1 ][ q.front().second ] )
    {
      w[ q.front().first - 1 ][ q.front().second ] = w[ q.front().first ][ q.front().second ] + 1 ;
      q.push( make_pair( q.front().first - 1 , q.front().second ) ) ;
    }

    if( !w[ q.front().first + 1 ][ q.front().second ] )
    {
      w[ q.front().first + 1 ][ q.front().second ] = w[ q.front().first ][ q.front().second ] + 1 ;
      q.push( make_pair( q.front().first + 1 , q.front().second ) ) ;
    }

    if( !w[ q.front().first ][ q.front().second - 1 ] )
    {
      w[ q.front().first ][ q.front().second - 1 ] = w[ q.front().first ][ q.front().second ] + 1 ;
      q.push( make_pair( q.front().first , q.front().second - 1 ) ) ;
    }

    if( !w[ q.front().first ][ q.front().second + 1 ] )
    {
      w[ q.front().first ][ q.front().second + 1 ] = w[ q.front().first ][ q.front().second ] + 1 ;
      q.push( make_pair( q.front().first , q.front().second + 1 ) ) ;
    }

    q.pop();
  }
}

bool isNotAllRipen()
{
  for( int i = 1 ; i <= r ; i++ )
    for( int j = 1 ; j <= c ; j++ )
      if( !w[ i ][ j ] )
        return true ;
  return false ;
}


int main( void )
{
  LoadMatrix() ;

  BFS() ;
  // ShowData() ;

  if( isNotAllRipen() )
    count = -1 ;

  // cout << q.front().second.first ;
  if( count == -1 )
    cout << count << "\n" ;
  else
    cout << count - 1 << "\n" ;
}
