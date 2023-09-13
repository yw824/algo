#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

int m ; // 가로
int n ; // 세로
int** w ; // 입력받는 배열
int** d ; //  누적삽 배열
int ans ;

void LoadMatrix()
{
  cin >> n >> m ;
  w = new int*[ n + 1 ] ;
  d = new int*[ n + 1 ] ;

  ans = 0 ;
  int len ;
  string str ; // n개의 문자열로 들어온다. -> 문자열로 받은 다음 m개의 문자로 쪼개서 받아준다.
  for( int i = 0 ; i <= n ; i++ )
  {
    w[ i ] = new int[ m + 1 ]{ 0 } ;
    d[ i ] = new int[ m + 1 ]{ 0 } ;

    if( i < n )
    {
      cin >> str ;
      len = ( int )str.length() ;
      for( int j = 0 ; j < m ; j++ )
      {
        w[ i ][ j ] = str[ j ] - 48 ;
        if( w[ i ][ j ] )
          ans = 1 ; // 1이 하나라도 있으면 최소값 = 1
      }
    }
  }
}

int getMin( int a , int b , int c )
{
  int lim = a ;
  if( lim > b ) lim = b ;
  if( lim > c ) lim = c ;

  return lim ;
}

void set( int x , int y , int in )
{
  int xtemp = x ;
  int ytemp = y ;
  for( ; xtemp >= 0 ; xtemp-- )
    d[ xtemp ][ y ] = in ;
  for( ; ytemp >= 0 ; ytemp-- )
    d[ x ][ ytemp ] = in ;

}

// DP :
// 맨 뒤쪽 항부터 하나씩 열-행 순으로 오면서 ,
// 자신과 자신 우칙 , 자신 아래측 , 자신 오른쪽+아래측이 1 이상이면
// 자신 우측 , 자신 아래측 , 자신 오른쪽+아래측 중 최소값 구해서 : getMin()
// 그 값에 1 더한다.
// 아니면 d[ i ][ j ]는 자기 자신이다.

// 계산한 후 , 자신의 값을 ->
// 자신과 같은 행과 열에 있는 앞 d값들에게 자신의 값으로 모두 설정해 준다. : set()
void DP()
{
  if( !ans ) // 1이 하나라도 없으면 구할 필요가 없다. 그냥 0이다.
    return ;
  for( int i = n - 1 ; i >= 0 ; i-- )
  {
    for( int j = m - 1 ; j >= 0 ; j-- )
    {
      if( w[ i ][ j ] && w[ i + 1 ][ j ] && w[ i ][ j + 1 ] && w[ i + 1 ][ j + 1 ] )
      {
        // cout << "i : " << i << " , j : " << j << "\n" ;
        d[ i ][ j ] = getMin( d[ i + 1 ][ j ] , d[ i ][ j + 1 ] , d[ i + 1 ][ j + 1 ] ) ;
        d[ i ][ j ] += 1 ;
        if( d[ i ][ j ] > ans )
          ans = d[ i ][ j ] ;
      }
      else
        d[ i ][ j ] = w[ i ][ j ] ;

      set( i , j , d[ i ][ j ] ) ;
    }
  }

}

void ShowData()
{
  for( int i = 0 ; i < n ; i++ )
  {
    for( int j = 0 ; j < m ; j++ )
      cout << d[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  LoadMatrix() ;
  DP() ;
  cout << pow( ans , 2 ) << "\n" ;
  // ShowData() ;
}
