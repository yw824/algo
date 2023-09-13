#include <iostream>
using namespace std ; 

int n ; 
int* ques ; 

void Load_Score()
{
	cin >> n ; 
	ques = new int[ n ] ; 
	for( int i = 0 ; i < n ; ++i )
		cin >> ques[ i ] ; 
}

int getScore()
{
	int accu = 0 ; 
	int ans = 0 ; 
	for( int i = 0 ; i < n ; ++i )
	{
		if( ques[ i ] == 0 )
		{
			accu = 0 ; 
			continue ; 
		}
		accu += 1 ; 
		ans += accu ; 
	}
	return ans ;  
}

int main( void )
{
	Load_Score() ; 
	cout << getScore() << '\n' ; 
}