#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

bool* visited ; // 방문 여부
int lim ; // 부등호 개수
char* arr ; // 부등호 배열
vector< int > v ; // 값 저장할 벡터
vector< int > n ; // 0 ~ 9 저장된 벡터
bool status ; // 출력했는지 안했는지 판단 ( false : 출력X , true : 출력 )

void Load()
{
  cin >> lim ;
  arr = new char[ lim ] ;
  for( int i = 0 ; i < lim ; i++ )
    cin >> arr[ i ] ;

  visited = new bool[ 10 ]{ false } ;
  for( int i = 9 ; i >= 0 ; i-- )
    n.push_back( i ) ;

  status = false ;
}

bool Check()
{
  for( int i = 0 ; i < lim ; i++ )
  {
    // cout << i << " : " << n[ v[i] ] << " " << arr[ i ] << " " << n[ v[i+1] ] << "\n" ;
    if( arr[ i ] == '<' )
    {
      if( n[ v[i] ] > n[ v[i+1] ] )
        return false ;
    }
    else // '>'
    {
      if( n[ v[i] ] < n[ v[i+1] ] )
        return false ;
    }
  }
  return true ;
}

void Print()
{
  if( !Check() )
    return ;

  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << n[ *iter ] ;
  cout << "\n" ;

  status = true ;
}

void Permutations( int cnt )
{
  if( status ) // 만약 이전에 Print 했으면 계속 벗어나기
    return ;

  if( cnt == lim + 1 ) // 최대 도달했으면 Print
  {
    Print() ;
    return ;
  }

  for( int i = 0 ; i < 10 ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      v.pop_back() ;
      visited[ i ] = false ;
    }
}

int main( void )
{
  Load() ;
  // cout << "----------------LARGE----------------\n" ;
  Permutations( 0 ) ;

  for( int i = 0 ; i < 10 ; i++ ) // 방문 여부 초기화
    visited[ i ] = false ;
  v.clear() ; // 저장하는 벡터 지우기
  reverse( n.begin() , n.end() ) ; // 배열 최소로 뒤집기
  status = false ;

  // cout << "----------------SMALL----------------\n" ;
  Permutations( 0 ) ;
}
