#include <iostream>
#include <string>
using namespace std ;

int main( void )
{
	string str ; // 알파벳 대문자로만 이루어져 있다.  
	int len ; 
	// Z의 다음 숫자는 A

	int test ; 
	cin >> test ; 
	int i ; 
	char c ;  
	for( int x = 1 ; x <= test ; ++x )
	{
		cin >> str ; 
		len = ( int )str.length() ; 

		cout << "String #" << x << "\n" ; 
		for( i = 0 ; i < len ; ++i )
		{
			c = char( ( str[ i ] -'A' + 1 ) % 26 + 'A' ) ; 
			cout << c ; 
		}
		cout << "\n\n" ; 
	}
}