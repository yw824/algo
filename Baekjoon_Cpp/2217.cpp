#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector < int > v;

  while( n-- )
  {
    int temp;
    cin >> temp;
    v.push_back( temp );
  }

  sort ( v.begin() , v.end() ) ;

  int max = 0 ;
  for( int i = 0 ; i < v.size() ; i++ )
  {
    if( max < v[i] * (v.size() - i ) )
      max = v[i] * ( v.size() - i );
  }
  cout << max;
}
// 예시 : 10 25 40 75 75 로 해보기
