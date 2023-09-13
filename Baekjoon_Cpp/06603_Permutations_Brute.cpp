#include <iostream>
#include <vector>
using namespace std ;

int n ; // 원소 수
int* w ; // 내용 담는 배열
vector< int > v ;
bool* visited ;

int Load() // 입력받기 및 메모리 할당
{
  cin >> n ;
  if( !n ) return n ;

  w = new int[ n ] ;
  visited = new bool[ n ]{ false } ;

  for( int i = 0 ; i < n ; i++ )
    cin >> w[ i ] ;

  return n ;
}

void UnLoad() // 매 반복마다 다시 설정해야 하므로 마지막에 메모리 해제
{
  v.clear() ;
  delete[] w ;
  delete[] visited ;
}

void Print() // 내용물 담은 벡터 출력
{
  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << w[ *iter ] << " " ;
  cout << "\n" ;
}

void Permutations( int cnt )
{
  if( cnt == 6 ) // 로또니까
  {
    Print() ;
    return ;
  }

  int top ;
  if( !v.size() ) top = -1 ;
  else top = v.back() ;

  for( int i = top + 1 ; i < n ; i++ ) // 오름차순으로 출력
  {
    v.push_back( i ) ;
    Permutations( cnt + 1 ) ;
    v.pop_back() ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);
  while( 1 )
  {
    if( !Load() ) break ; // 0이면 루프 벗어나기

    Permutations( 0 ) ; // 재귀
    UnLoad() ; // 메모리 해제
    cout << "\n" ; // 출력값에서 루프마다 구분하기 위해 한칸 띈다.
  }
}
