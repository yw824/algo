#include <iostream>
using namespace std ;

int n ; // 체스판 길이 ( 가로 세로 길이 같다. )
int* col ; // 각 줄에서 Queen이 위치하는 곳

int count ; // 가능한 경우의 수 세기

// 백트래킹 : 상태공간트리 설정하고
// DFS 수행하며 매번 유망함수로 판단

// 초기 배열 설정
void LoadMatrix()
{
  // printf("rows or cols : ");
  cin >> n ;

  col = new int[ n + 1 ]{ 0 } ;

  // 아직 탐색 안했으므로 0 할당
  count = 0 ;
}

// 백트래킹 : 유망 함수 필요 - 가로 , 세로 , 대각선 모두 없음
bool isPromising( int i ) // i : level
{
  bool Switch = true ;
  int k = 1 ;

  while ( k < i && Switch )
  {
    if( col[ i ] == col[ k ] || abs( col[ i ] - col[ k ] ) == abs( i - k ) )
      Switch = false ;
    k++ ;
  }
  return Switch ;
}

// N-Queens 함수 - 아무것도 하지 않은 0단계부터 시작
// 그래야 1번쨰 줄 ( 1단계 )에 아무데나 놓을 수 있음
void N_Queens( int k )
{
  int j ;
  if ( isPromising( k ) ) // 현재 노드에 도달하였는데 유망한지 안한지 판단 필요
    if( k == n ) // 마지막 단계까지 도달하였을 경우
    {
      ++count ; // 경우의 수에 하나 추가
      // for( int i = 1 ; i <= n ; i++ )
      //   printf( "col[ %d ] : %d \n" , i , col[ i ] ) ;
      // printf( "==================\n" ) ;
    }
    else // 아직 도달 안했으면
      for( j = 1 ; j <= n ; j++ )
      {
        col[ k + 1 ] = j ; // 매 다음 모든 노드에 놓아보고
        N_Queens( k + 1 ) ; // 재귀함수 실행
      }
}

int main(void)
{
  LoadMatrix() ;

  N_Queens( 0 ) ; // 처음에 아무것도 고르지 않은 상태 , level 0 으로 가야 함
  cout << count << "\n" ;
}
