#include <iostream>
using namespace std ; 

int main( void ) 
{
	int* w = new int[ 201 ]{ 0 } ;

	int n , i , input ; 
	cin >> n ; 
	for( i = 0 ; i < n ; ++i )
	{
		cin >> input ; 
		w[ input + 100 ] += 1 ;
	} 

	int target ; 
	cin >> target ; 
	cout << w[ target + 100 ] << "\n" ; 
}