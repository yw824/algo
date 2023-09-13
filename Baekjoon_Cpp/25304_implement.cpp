#include <iostream>
using namespace std ;

int main( void )
{
	int total ; 
	cin >> total ; 
	
	int addsum = 0 ; 
	int cnt , price ; 
	int orders ; 

	cin >> orders ; 
	while( orders-- )
	{
		cin >> price >> cnt ; 
		addsum += price * cnt ;
	}
	if( total == addsum )
		cout << "Yes" << "\n" ; 
	else
		cout << "No" << "\n" ; 
	
	return 0 ; 
}