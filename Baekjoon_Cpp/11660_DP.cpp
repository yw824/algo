#include <iostream>
using namespace std ;

// DP - 누적합 문제

// 주어진 문제 자체에 표현 모호함이 있다.
// 시작 항 부터 끝항까지 구하는 것이 아니라
// 시작항으로부터 끝항까지로 형성되는
// 직사각형 내의 값들의 합을 구하는 것이다.

int n ; // 정사각행렬의 변 길이
int m ; // 구해야 하는 테스트 케이스 수

int** d ; // 누적합 저장하는 배열


// 맨 처음부터 다른 배열에 원래 입력값 저장하지 않고
// 받으면서 더해서 누적합 값으로 저장하자.
// d[ i ][ j ] = d[ i ][ j - 1 ] + 현재 입력받은 값
void Load()
{
  cin >> n >> m ;

  d = new int*[ n + 1 ] ;

  for( int i = 1 ; i <= n ; i++ )
  {
    d[ i ] = new int[ n + 1 ]{ 0 } ;

    int input ;
    for( int j = 1 ; j <= n ; j++ )
    {
      cin >> input ;
      d[ i ][ j ] = d[ i ][ j - 1 ] + input ;
    }

  }
}


// 사각형 단위이므로
// 한 줄마다 끊으면서
// 해당 항은 이전항에 해당 셀에 들어오는 값을 더한다.

// 예 : ( 1 , 2 ) ~ ( 3 , 4 ) =
// d[ 1 , 4 ] - d[ 1 , 1 ] +
// d[ 2 , 4 ] - d[ 2 , 1 ] +
// d[ 3 , 4 ] - d[ 3 , 1 ]

void PrefixSum()
{
  int x1 , y1 , x2 , y2 , sum ;

  while( m-- )
  {
    sum = 0 ;
    cin >> x1 >> y1 >> x2 >> y2 ;

    // Load 함수에서 줄 단위로 누적합 구했기 때문에
    for( int i = x1 ; i <= x2 ; i++ )
      sum += ( d[ i ][ y2 ] - d[ i ][ y1 - 1 ] ) ;

    cout << sum << "\n" ;
  }
}

int main( void )
{
  // 이 두 문구 넣지 않으면 시간초과 발생
  cin.tie(NULL) ;
  ios_base::sync_with_stdio(false) ;

  Load() ;

  PrefixSum() ;
}
