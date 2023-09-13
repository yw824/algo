#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int l ; // 서로 다른 L개의 알파벳 소문자들로 구성되며
int c ; // 암호로 사용했을 법한 문자의 종류로는 c가지 있다고 추정
char* alpha ;
bool* visited ;
vector< int > v ;
int top ;

void Load()
{
  cin >> l >> c ;
  alpha = new char[ c ] ;
  visited = new bool[ c ]{ false } ;

  for( int i = 0 ; i < c ; i++ )
    cin >> alpha[ i ] ;

  sort( alpha , alpha + c ) ;

  v.clear() ;
  top = -1 ;
}

bool Check()
{
  int sound = 0 ; // 자음 갯수
  int vowel = 0 ; // 모음 갯수
  vector< int >::iterator iter ;
  char t ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
  {
    t = alpha [ *iter ] ;
    if( t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' )
      ++vowel ;
    else
      ++sound ;
  }

  if( sound < 2 ) // 자음 최소 2개 있어야 한다.
    return false ;
  if( vowel < 1 ) // 모음 최소 1개 있어야 한다.
     return false ;
  return true ;
}

void Print()
{
  if( !Check() )
    return ;

  vector< int >::iterator iter ;
  for( iter = v.begin() ; iter != v.end() ; ++iter )
    cout << alpha[ *iter ] ;
  cout << "\n" ;
}

void Permutations( int cnt )
{
  if( cnt == l )
  {
    Print() ;
    return ;
  }

  if( v.empty() )
    top = -1 ;
  else
    top = v.back() ;

  for( int i = top + 1 ; i < c ; i++ )
    if( !visited[ i ] )
    {
      visited[ i ] = true ;
      v.push_back( i ) ;
      Permutations( cnt + 1 ) ;
      v.pop_back() ;
      visited[ i ] = false ;
    }
}

void ShowData()
{
  for( int i = 0 ; i < c ; i++ )
    cout << alpha[ i ] << " " ;
  cout << "\n" ;
}

int main( void )
{
  Load() ;
  // ShowData() ;
  Permutations( 0 ) ;
}
