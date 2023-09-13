#include <iostream>
using namespace std ;

int n ; // 가로 , 세로 사이즈
int count ; // 구역 수 체크
// n * n 그림
int** w ; // 그림 배열
int** d ; // 방문 여부 저장 배열

// R = 1 , G = 2 , B = 5
// 적녹은 차이가 1이 나게끔 설정

// 초기 데이터 받아오기 및 설정
void LoadMatrix()
{
  cin >> n ;

  w = new int*[ n ] ;
  d = new int*[ n ] ;

  char c ;
  for( int i = 0 ; i < n ; i++ )
  {
    d[ i ] = new int[ n ]{ 0 } ;
    w[ i ] = new int[ n ]{ 0 } ;
    for( int j = 0 ; j < n ; j++ )
    {
      cin >> c ;
      if( c == 'R' )
        w[ i ][ j ] = 1 ; // R = 1
      else if( c == 'G' )
        w[ i ][ j ] = 2 ; // G = 2
      else if( c == 'B' )
        w[ i ][ j ] = 5 ; // B = 5
    }
  }

  count = 0 ;
}

// DFS 두번째 하기 전에 d 배열 및 count 초기화
void Init()
{
  count = 0 ;
  for( int i = 0 ; i < n ; i++ )
    for( int j = 0 ; j < n ; j++ )
      d[ i ][ j ] = 0 ;
}

// 상하좌우 색이 같을 때 , 그리고 방문 안했을 때에만 인접노드 이동하여 탐색
void DFS_Neg( int i , int j ) // 적녹색약 음성
{
  // printf("current = ( %d , %d )\n" , i , j ) ;
  d[ i ][ j ] = 1 ;
  if( i >= 1 && !d[ i - 1 ][ j ] && w[ i - 1 ][ j ] == w[ i ][ j ] )
    DFS_Neg( i - 1 , j ) ;
  if( i < n - 1 && !d[ i + 1 ][ j ] && w[ i + 1 ][ j ] == w[ i ][ j ] )
    DFS_Neg( i + 1 , j ) ;
  if( j >= 1 && !d[ i ][ j - 1 ] && w[ i ][ j - 1 ] == w[ i ][ j ] )
    DFS_Neg( i , j - 1 ) ;
  if( j < n - 1 && !d[ i ][ j + 1 ] && w[ i ][ j + 1 ] == w[ i ][ j ] )
    DFS_Neg( i , j + 1 ) ;
}

// 양성이면 적녹 차이가 1 이내일 때 같다고 인식
bool isEqual( int x1 , int y1 , int x2 , int y2 )
{
  return ( w[ x1 ][ y1 ] - w[ x2 ][ y2 ] <= 1 ) && ( w[ x1 ][ y1 ] - w[ x2 ][ y2 ] >= -1 ) ;
}

// 상하좌우 색 차이가 1 이내일 때 , 그리고 방문 안했을 때에만 인접노드 이동하여 탐색
void DFS_Pos( int i , int j ) // 적녹색약 양성
{
  d[ i ][ j ] = 1 ;
  if( i >= 1 && !d[ i - 1 ][ j ] && isEqual( i - 1 , j , i , j ) )
    DFS_Pos( i - 1 , j ) ;
  if( i < n - 1 && !d[ i + 1 ][ j ] && isEqual( i + 1 , j , i , j ) )
    DFS_Pos( i + 1 , j ) ;
  if( j >= 1 && !d[ i ][ j - 1 ] && isEqual( i , j - 1 , i , j ) )
    DFS_Pos( i , j - 1 ) ;
  if( j < n - 1 && !d[ i ][ j + 1 ] && isEqual( i , j + 1 , i , j ) )
    DFS_Pos( i , j + 1 ) ;
}

// DFS 사용
int main( void )
{
  LoadMatrix() ;

  // DFS_Neg ( 순차탐색 )
  for( int i = 0 ; i < n ; i++ )
    for( int j = 0 ; j < n ; j++ )
      if( !d[ i ][ j ] )
      {
        // cout << "------------------\n" ;
          ++count ; // 새로운 블록 방문하였으므로 count 하나 증가
          DFS_Neg( i , j ) ; // 새로운 블록에서 DFS 실행
      }
  cout << count << " " ;

  // 한번 DFS 실시했으므로 다시 초기화
  Init() ;

  // DFS_Pos ( 순차탐색 )
  for( int i = 0 ; i < n ; i++ )
    for( int j = 0 ; j < n ; j++ )
      if( !d[ i ][ j ] )
      {
        // cout << "------------------\n" ;
          ++count ; // 새로운 블록 방문하였으므로 count 하나 증가
          DFS_Pos( i , j ) ; // 새로운 블록에서 DFS 실행
      }
  cout << count << "\n" ;

}
