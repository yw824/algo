#include <iostream>
using namespace std ;

int main( void ) 
{
	bool* arr = new bool[ 31 ]{ false };
	int i, input;
	for(i = 1 ; i <= 28 ; ++i) 
	{
		cin >> input ;
		arr[ input ] = true ;
	}
	for(i = 1 ; i <= 30 ; ++i ) 
	{
		if( !arr[ i ] )
			cout << i << "\n" ;
	}
}