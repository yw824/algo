#include <iostream>
using namespace std ;

int n ; // 원하는 값
int* w ; // 중간 결과 메모한 배열
int* d ; // 방문 여부 확인 배열

// 방법론 :
// 접근할 때마다 n까지 5 주기의 값을 +1씩 갱신
// 접근할 때마다 n까지 3 주기의 값을 +1씩 갱신
// 5 주기가 3주기보다 개수가 더 적을 것이므로 우선순위가 앞선다.
// -> 5 주기 돈 후 방문여부를 방문했다고 표기한다. d[ i ] = 1 ;


void LoadMatrix()
{
  cin >> n ;

  // 5 이하일 경우에는 루프를 돌 필요가 없음
  // 따라서 그냥 디폴트로 구할 수 잆는 경우인 index = 5까지를 구함
  if( n <= 5 )
  {
    w = new int[ 6 ]{ 0 } ;
    d = new int[ 6 ]{ 1 } ;
  }
  else // 아닌 경우에는 루프 돌아야 하므로 n + 1 까지 배열 할당
  {
    w = new int[ n + 1 ]{ 0 } ;
    d = new int[ n + 1 ]{ 0 } ;
    for( int i = 1 ; i <= n ; i++ )
      w[ i ] = 200000 ; // max : 200000이라고 설정 - 구할 방법이 없는 경우
  }

  w[ 1 ] = 200000 ; // 방법 없음
  w[ 2 ] = 200000 ; // 방법 없음
  w[ 3 ] = 1 ; // 1가지 방법 가능
  w[ 4 ] = 200000 ; // 방법 없음
  w[ 5 ] = 1 ; // 1가지 방법 가능
  for( int i = 1 ; i <= 5 ; i++ ) // 1부터 5까지는 미리 설정해 놓았으므로 방문 여부 표시
    d[ i ] = 1 ;

  for( int i = 3 ; i <= n ; i++ ) // 3부터 일일이 루프돌며 최저값 갱신
  {
    int current = i ;
    while( current <= n && w[ current ] < 200000 ) // 5씩 더해가며 갱신 - 우선순위 앞선다
    {
      if( w[ current + 5 ] > w[ current ] + 1 ) // 다음 5 주기의 값이 현재 값 + 1 보다 클 경우
        w[ current + 5 ] = w[ current ] + 1 ;
      current += 5 ;
      d[ current ] = 1 ; // 다른 경우에 겹쳐도 이 경우에 구한 값이 가장 적은 수에 해당 - 비교 안하게끔 설정
    }
    current = i ; // 다시 현재 값으로 초기화하여 3씩 더해가며 갱신
    while( current <= n && w[ current ] < 200000 ) // 다음 3 주기의 값이 현재 값 + 1 보다 클 경우
    {
      if( w[ current + 3 ] > w[ current ] + 1 )
        w[ current + 3 ] = w[ current ] + 1 ;
      current += 3 ;
    }
  }
}
void ShowData() // 구한 값 모두 출력
{
  cout << "----------ShowData--------\n" ;
  for( int i = 1 ; i <= n ; i++ )
    printf( "w[ %d ] : %d \n" , i , w[ i ] ) ;
  cout << "--------------------------\n" ;
}

int main( void )
{
  LoadMatrix() ;
  // ShowData() ; // 5000일 때 ShowData는 작동 안함

  if( w[ n ] >= 200000 ) // max값보다 클 때 -1 출력 : 문제의 요구사항
  {
    cout << "-1" << "\n" ;
    return 0 ;
  }
  cout << w[ n ] << "\n" ; //  max보다 작은 의미있는 값일 경우 그대로 출력
}
