#include <iostream>
#include <vector>
using namespace std ;

vector< int > v ; // 최고자릿수 저장하는 벡터
int n ; // 최고자릿 수 중 제일 큰 것
long long** w ; // DP 배열

// long long으로 선언해야 함
// 최고 인덱스가 최대 64인데, 64 실행해 보면 답에서 음수나옴 ( 자릿수초과 )
// -> long long으로 선언해야 함
void LoadMatrix()
{
  w = new long long*[ n + 1 ] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    w[ i ] = new long long[ 10 ]{ 0 } ;
    w[ i ][ 9 ] = 1 ; // 최고자릿수가 9면 경우의 수가 무조건 1
    if( i == 1 )
      for( int j = 0 ; j <= 9 ; j++ )
        w[ i ][ j ] = 1 ; // 1의 자릿수는 경우의 수가 무조건 1
  }
}

void ShowData() // 배열 출력
{
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 0 ; j < 10 ; j++ )
      cout << w[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

// 그 전 자릿수가 본인인 거 + 그 전 자릿수가 본인 - 1 인거
void DP()
{
  for( int i = 2 ; i <= n ; i++ )
    for( int j = 8 ; j >= 0 ; j-- ) // DP - 8부터 0으로 하나씩 내려가면서 수행
      w[ i ][ j ] = w[ i ][ j + 1 ] + w[ i - 1 ][ j ] ;

  vector< int >::iterator iter ; // 자릿수 벡터 돌면서 인덱스 확인
  for( iter = v.begin() ; iter != v.end() ; ++iter )
  {
    int index = *iter ;
    long long temp = 0 ;
    for( int i = 0 ; i < 10 ; i++ ) // 0부터 9까지 다 더해서 확인
      temp += w[ index ][ i ] ;
    cout << temp << "\n" ;
  }
}

int main( void )
{
  int order ;
  cin >> order ;
  n = 0 ;

  while( order-- )
  {
    int temp ;
    cin >> temp ;
    v.push_back( temp ) ;
    if( n < temp ) n = temp ;
  }

  LoadMatrix() ;
  //ShowData() ;
  DP() ;
  //ShowData() ;
}
