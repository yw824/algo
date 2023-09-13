#include <iostream>
#include <string>
using namespace std ;

string str ; // 주어지는 문자열
int len ;
vector< char > v ; // 문자열 나누는 벡터
int* num ;
bool minus ;

void Load()
{
  cin >> str ;
  len = str.length() ;

  minus = false ;

  for( int i = 0 ; i < len ; i++ )
  {
    if( str[ i ] == '-' || str[ i ] == '+' )
    {
      int index = -1 ;
      char* temp = new char[ len ] ;
      for( vector< char >::iterator iter = v.begin() ; iter!= v.end() ; ++iter )
      {
        temp[ ++index ] = *iter ;
      }
      while( index-- )
      {
        temp[ index ]
      }
      v.clear() ;
    }
    else
    {
      v.push_back( str[ i ] ) ;
    }
  }
}

int main( void )
{
  Load() ;
}
