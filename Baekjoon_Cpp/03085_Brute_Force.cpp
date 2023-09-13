#include <iostream>
using namespace std ;

int n ;
char** w ;
int count ;

int X[ 4 ] = { -1 , 1 , 0 , 0 } ;
int Y[ 4 ] = { 0 , 0 , -1 , 1 } ;

int getMax()
{
  int ans = 0 ;
  int temp = 1 ; // 자신을 포함하면 최소 1이여야 함
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
    {
      if( w[ i ][ j ] != w[ i ][ j - 1 ] )
      {
        if( ans < temp ) ans = temp ;
        temp = 1 ;
      }
      else
        temp++ ;
    }
  }
  if( temp )
    if( ans < temp )
      ans = temp ;
  temp = 1 ;

  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
    {
      if( w[ j ][ i ] != w[ j - 1 ][ i ] )
      {
        if( ans < temp ) ans = temp ;
        temp = 1 ;
      }
      else
        temp++ ;
    }
  }
  if( temp )
    if( ans < temp )
      ans = temp ;

  return ans ;
}

void LoadMatrix()
{
  string str ;
  cin >> n ;
  w = new char*[ n + 2 ] ;
  for( int i = 0 ; i <= n + 1 ; i++ )
  {
    w[ i ] = new char[ n + 2 ] ;

    for( int j = 0 ; j <= n + 1 ; j++ )
      w[ i ][ j ] = '-' ;

    if( i && i <= n )
    {
      cin >> str ;

      for( int j = 1 ; j <= n ; j++ )
        w[ i ][ j ] = str[ j - 1 ] ;
    }
  }

  count = 0 ;
  int ans = getMax() ;
  if( ans > count ) count = ans ;
}

void ShowData()
{
  for( int i = 0 ; i <= n + 1 ; i++ )
  {
    for( int j = 0 ; j <= n + 1 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

void swap( int x1 , int y1 , int x2 , int y2 )
{
  //cout << "(" << x1 << "," << y1 << " // " << x2 << "," << y2 << ")" << "\n" ;
  char temp = w[ x1 ][ y1 ] ;
  w[ x1 ][ y1 ] = w[ x2 ][ y2 ] ;
  w[ x2 ][ y2 ] = temp ;
}

void transform( int x , int y )
{
  int ans ;
  for( int i = 0 ; i < 4 ; i++ )
  {
    swap( x , y , x + X[ i ] , y + Y[ i ] ) ;
    //ShowData() ;
    ans = getMax() ;
    if( ans > count ) count = ans ;
    swap( x , y , x + X[ i ] , y + Y[ i ] ) ;
    //ShowData() ;
  }
}


int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  LoadMatrix() ;
  // ShowData() ;

  for( int i = 1 ; i <= n ; i++ )
    for( int j = 1 ; j <= n ; j++ )
      transform( i , j ) ;

  cout << count << "\n" ;
}
