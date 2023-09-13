#include <iostream>
using namespace std ;

// 골드바흐 문제

bool d[ 10001 ]{ false } ;

// 소수 판별
void Prime()
{
  for( int i = 2 ; i <= 10000 ; i++ )
    d[ i ] = false ;
  d[ 1 ] = true ;
  // 1은 소수가 아니므로 2부터 시작
  for( int i = 2 ; i <= 10000 ; i++ )
  {
    // i가 소수가 아닐 경우에 넘어가기
    if( d[ i ] ) continue ;

    // 만약 소수일 경우에
    // 해당 소수로 해당 수보다 큰 수들을 나눠본다.
    for( int j = i + 1 ; j <= 10000 ; j++ )
      if( !( j % i ) ) // 만약 해당 소수로 나눠지는 수가 있으면
        d[ j ] = true ; // 그 수는 소수가 아니다.
  }
}

void ShowData()
{
  for( int i = 0 ; i < 50 ; i++ )
  {
    for( int j = 1 ; j <= 20 ; j++ )
      cout << d[ i * 20 + j ] << " " ;
    cout << "\n" ;
  }
}

void GoldBach()
{
  int temp , order , input ;
  cin >> order ;

  while( order-- )
  {
    cin >> input ;
    temp = input / 2 ;
    while( temp )
    {
      if( !d[ temp ] && !d[ input - temp ] )
      {
        if( temp > input - temp )
          cout << input - temp << " " << temp << "\n" ;
        else
          cout << temp << " " << input - temp << "\n" ;
        break ;
      }
      temp-- ;
    }

  }
}

int main( void )
{
  Prime() ;
  // ShowData() ;
  GoldBach() ;
}
