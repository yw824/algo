#include <iostream>
using namespace std ;

int n ; // 시험장
int* a ; // 시험장 당 수험생 수
int b ; // 감독관 당 수험생 수 - 총 1명만 있어야 한다
int c ; // 부감독관 당 수험생 수 - 여러 명 있어도 된다.
long long count ; // 총 감독관 수

void Set()
{
  cin >> n ;
  a = new int[ n ] ;
  for( int i = 0 ; i < n ; i++ )
    cin >> a[ i ] ;

  cin >> b >> c ;
  count = 0 ;
}

void Count()
{
  int temp ;
  // 정감독관 수 및 부감독관 수 count
  for( int i = 0 ; i < n ; i++ )
  {
    a[ i ] -= b ;
    ++count ;
    if( a[ i ] < 0 ) a[ i ] = 0 ;

    temp = a[ i ] / c ;
    if( a[ i ] % c )
      temp++ ;
    count += temp ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);

  Set() ;
  Count() ;
  cout << count << "\n" ;
}
