#include <iostream>
#include <string>
using namespace std ; 

int cnt ; 
string s ; // 문자열은 함수로 넘겨주면 시간 초과 발생 , 전역 변수로 설정하는 게 유리

int recursion( int l , int r )
{
	cnt += 1 ; 
    if( l >= r ) 
    	return 1 ;
    else if( s[ l ] != s[ r ] ) 
    	return 0 ;
    else 
    	return recursion( l + 1 , r - 1 ) ;
}

int isPalindrome() {
	cnt = 0 ; 
	int len = ( int )s.length() ; 
	return recursion( 0 , len - 1 ) ;
}

int main( void )
{
	int n ; 
	cin >> n ; 
	while( n-- )
	{
		cin >> s ; 
		cout << isPalindrome() << " " << cnt << "\n" ; 
	}
}