#include <iostream>
#include <string>
using namespace std ;

int n ; // 피연산자의 수 ( 1 ~ 26 )
float* var ; // 피연산자 순서대로 주어지는 값

string str ; // 주어지는 문자열
int len ; // 주어지는 문자열의 길이

float* stack ; // 스택
int top ; // 스택에 사용할 인덱스

float ans ; // 연산 결과

void Init()
{
  cin >> n ;

  var = new float[ n ]{ 0 } ;
  stack = new float[ n ]{ 0 } ;
  top = -1 ;

  cin >> str ;
  len = str.length() ;

  int num ;
  for( int i = 0 ; i < n ; i++ )
  {
    cin >> num ;
    var[ i ] = float( num ) ;
  }

  ans = 0 ;
}

void Sol()
{
  int a , b ;
  for( int i = 0 ; i < n ; i++ )
  {
    if( (int)str[ i ] >= 65 && (int)str[ i ] <= 90 )
    {
      stack[ ++top ] = var[ str[ i ] - 65 ] ;
      continue ;
    }

    b = stack[ top-- ] ;
    a = stack[ top-- ] ;
    if( str[ i ] == '*' )
    {
      stack[ ++top ] = a * b ;
      continue ;
    }
    else if( str[ i ] == '+' )
    {
      stack[ ++top ] = a + b ;
      continue ;
    }
    if( str[ i ] == '-' )
    {
      stack[ ++top ] = a - b ;
      continue ;
    }
    if( str[ i ] == '/' )
    {
      stack[ ++top ] = a / b ;
      continue ;
    }
  }
}


// 스택 사용
int main( void )
{
  Init() ;
  Sol() ;
  for( int i = 0 ; i <= top ; i++ )
    cout << stack[ i ] << " , " ;
  ans = stack[ top ] ;
  printf("%.2f \n " , ans ) ;
}
