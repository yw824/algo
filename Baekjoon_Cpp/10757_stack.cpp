#include <iostream>
#include <stack>
#include <string>
using namespace std ;


int main( void )
{
	stack< int > q ; 
	string str1 , str2 ; 
	int len1 , len2 ; 

	cin >> str1 >> str2 ; 
	len1 = str1.length() - 1 ; len2 = str2.length() - 1 ; 

	int maxlen = len1 ; 
	if( len2 > maxlen ) maxlen = len2 ; 

	int one , two , count = 0 , temp ;
	while( maxlen >= 0 )
	{
		one = 0 , two = 0 ; 
		if( len1 >= 0 )
			one = str1[ len1 ] - 48 ; 
		if( len2 >= 0 )
			two = str2[ len2 ] - 48 ; 

		temp = one + two + count ; 
		if( temp >= 10 )
			count = 1 ; 
		else
			count = 0 ; 
		// cout << temp << "\n" ; 
		q.push( temp % 10 ) ;

		--maxlen ; --len1 ; --len2 ;  
	}

	if( count == 1 )
		q.push( count ) ; 

	while( !q.empty() )
	{
		cout << q.top() ;
		q.pop() ; 
	}
	return 0 ; 
}