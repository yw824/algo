#include <iostream>
#include <string>
using namespace std ;

string s1 ;
string s2 ;
int len1 ;
int len2 ;
int** w ;
int ans ;

// 링크
// http://melonicedlatte.com/algorithm/2018/03/15/181550.html

void LoadMatrix()
{
  cin >> s1 ;
  cin >> s2 ;
  len1 = int( s1.length() ) ;
  len2 = int( s2.length() ) ;

  w = new int*[ len1 + 1 ] ;
  for( int i = 0 ; i <= len1 ; i++ )
    w[ i ] = new int[ len2 + 1 ]{ 0 } ;

  ans = 0 ;
}

void DP()
{
  for( int i = 1 ; i <= len1 ; i++ )
    for( int j = 1 ; j <= len2 ; j++ )
    {
    //  printf("s1[%d] : %c , s2[%d] : %c\n", i , s1[ i ] , j , s2[ j ] ) ;
      if( s1[ i - 1 ] == s2[ j - 1 ] )
        w[ i ][ j ] = w[ i - 1 ][ j - 1 ] + 1 ;
      else
      {
        w[ i ][ j ] = w[ i - 1 ][ j ] ;
        if( w[ i ][ j ] < w[ i ][ j - 1 ] )
          w[ i ][ j ] = w[ i ][ j - 1 ] ;
      }
    }
}

void ShowData()
{


  cout << "len1 : " << len1 << " , len2 : " << len2 << "\n" ;
  for( int i = 0 ; i <= len1 ; i++ )
  {
    for( int j = 0 ; j <= len2 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

//a 하고 b 넣으면 0 나와야 함

int main( void )
{
  LoadMatrix() ;
  DP() ;
  // ShowData() ;

  cout << w[ len1 ][ len2 ] << "\n" ;
}
