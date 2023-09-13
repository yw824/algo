#include <iostream>
using namespace std;

// 경로에 있는 수의 합 출력

int n ; // 삼각형 크기 = 배열 층수
int** w ;
int** d ;
int Max ;

void Load()
{
  cin >> n ;
  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new int[ i + 2 ]{ -1 } ;
    d[ i ] = new int[ i + 2 ]{ 0 } ;
    for( int j = 1 ; j <= i ; j++ )
      cin >> w[ i ][ j ] ;
    w[ i ][ i + 1 ] = -1 ;
  }
  d[ 1 ][ 0 ] = w[ 1 ][ 0 ] ;
  d[ 1 ][ 1 ] = w[ 1 ][ 1 ] ;
  d[ 1 ][ 2 ] = w[ 1 ][ 2 ] ;
  Max = d[ 1 ][ 1 ] ;
}

void ShowData()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 0 ; j <= i + 1 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

void DP()
{
  for( int i = 2 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= i + 1 ; j++ )
    {
      if( w[ i ][ j ] == -1 )
        continue ;
      d[ i ][ j ] = d[ i - 1 ][ j - 1 ] ;
      if( d[ i ][ j ] < d[ i - 1 ][ j ] )
        d[ i ][ j ] = d[ i - 1 ][ j ] ;

      d[ i ][ j ] += w[ i ][ j ] ;
      if( Max < d[ i ][ j ] )
        Max = d[ i ][ j ] ;
    }
  }
}

void ShowDP()
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= i ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main(void)
{
  Load() ;
  // ShowData() ; -- 입력까지는 완료

  DP() ;

  // ShowDP() ;
  cout << Max << "\n" ;
}
