#include <iostream>
#include <cmath>
using namespace std ;

int n ;
int m ;
int** w ;

int Min ;
int Max ;

void Load()
{
  string str ;
  cin >> n >> m ;
  Min = n ;
  if( m < Min ) Min = m ;

  w = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new int[ m + 1 ]{ 0 } ;
    cin >> str ;

    for( int j = 0 ; j < m ; j++ )
      w[ i ][ j + 1 ] = str[ j ] ;
  }

  Max = 0 ;
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= m ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

bool isEqual( int i , int j , int Min )
{
  if( w[ i ][ j ] != w[ i ][ j + Min ] ) return false ;
  if( w[ i ][ j ] != w[ i + Min ][ j ] ) return false ;
  if( w[ i ][ j ] != w[ i + Min ][ j + Min ] ) return false ;
  return true ;
}

void getMax()
{
  for( int k = 0 ; k < Min ; ++k )
    for( int i = 1 ; i + k <= n ; ++i )
      for( int j = 1 ; j + k <= m ; ++j )
        if( isEqual( i , j , k ) )
        {
          // printf( "i : %d , j : %d , Min : %d \n" , i , j , k + 1 ) ;
          if( k + 1 > Max )
            Max = k + 1 ;
        }
}

int main( void )
{
  Load() ;

  // ShowData() ;

  getMax() ;
  cout << pow( Max , 2 ) << "\n" ;
}
