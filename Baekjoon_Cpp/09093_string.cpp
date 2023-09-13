#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std ;

string str ;
int order ;

vector<string> split( string str , char Delimiter ) {
    istringstream iss( str );            // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}

void execute()
{
  str = "" ;
  getline( cin , str ) ;

  vector< string > result = split(str, ' ') ; // 구분자를 통해 벡터에 나눈 문자열을 담는다.
  vector<string>::iterator iter ;
  long int len ;
  for( iter = result.begin() ; iter != result.end() ; ++iter )
  {
    len = iter->length() ; // 나눠진 문자열 조각마다 길이를 재서 역으로 출력
    for( int i = len - 1 ; i >= 0 ; i-- )
       cout << (*iter)[ i ] ;
    cout << " " ; // 출력 후 빈칸
  }
  cout << "\n" ; // 한칸 전체 출력 후 한 줄 넘기기
}

int main( void )
{
  int order ;
  cin >> order ;
  getchar() ; // 숫자 받으면 input buffer에 엔터 남아서 꼭 한번 더 받아서 버려야 한다.
  //cin.ignore() ; // empty the cin input
  while( order-- )
    execute() ;
}
