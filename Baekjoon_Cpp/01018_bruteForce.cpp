#include <iostream>
using namespace std ;

int row ;
int col ;
int ans ;
char** arr ;

void Load()
{
  string str ;

  // 행 , 열 받기
  cin >> row >> col ;
  arr = new char*[ row + 1 ] ;

  for( int i = 1 ; i <= row ; i++ )
  {
    // 문자열로 받아서 하나씩 떼어 저장하기
    arr[ i ] = new char[ col + 1 ] ;
    cin >> str ;

    for( int j = 1 ; j <= col ; j++ )
      arr[ i ][ j ] = str[ j - 1 ] ;
  }
  ans = row * col ;
  // 최대로 다시 칠해야 하는 개수 : row * col 혹은 64
}

// 체스판 출력
void ShowData()
{
  for( int i = 1 ; i <= row ; i++ )
  {
    for( int j = 1 ; j <= col ; j++ )
      cout << arr[ i ][ j ] << " " ;
    cout << "\n" ;
  }
}

// 출발 행번호 + 8이 세로 끝에 닿을 때까지 *
// 출발 열번호 + 8이 가로 끝에 닿을 때까지
int getMin( int x , int y )
{
  int count1 = 0 , count2 = 0 ;
  // 행이 0번째( 시작 ) 부터 7번째( 끝 ) 까지 : 0 ~ 7
  for( int i = x ; i <= x + 7 ; i++ )
  {
    // 열이 0번째( 시작 ) 부터 7번째( 끝 ) 까지 : 0 ~ 7
    for( int j = y ; j <= y + 7 ; j++ )
    {
      // 시작이 W일 때 count
      if( arr[ i ][ j ] == 'W' )
      {
        if( ( i + j ) % 2 )
          count2++ ;
        else
          count1++ ;
      }
      else // 시작이 B일때 count
      {
        if( ( i + j ) % 2 )
          count1++ ;
        else
          count2++ ;
      }
    }
  }
  if( count1 > count2 ) return count2 ;
  return count1 ;
}

void Brute_Force()
{
  int temp ;
  // 행 끝이 세로 끝에 닿을 때까지 실행
  for( int i = 1 ; i + 7 <= row ; i++ )
  {
    // 열 끝이 가로 끝에 닿을 때까지 실행
    for( int j = 1 ; j + 7 <= col ; j++ )
    {
      temp = getMin( i , j ) ;
      if( ans > temp )
        ans = temp ;
    }
  }
}

int main( void )
{
  Load() ;
  // ShowData() ;

  Brute_Force() ;
  cout << ans << "\n" ;
}
