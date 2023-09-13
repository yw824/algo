#include <iostream>
#include <vector>
using namespace std ;

int main( void )
{
	int women , men , k ; 
	cin >> women >> men >> k ; 

	int rest, teams = 0 ; 
	// 1. men * 2 <= women : team = men , women_rest = women - men * 2
	if( men * 2 <= women )
	{
		teams = men ; 
		rest = women - men * 2 ; 
		while( rest < k ) // // 한 팀은 3명 단위, 3명을 rest로 추가해 준다. 
		{
			k -= rest ; 
			rest = 3 ; 
			teams -= 1 ; 
		}
	}

	// 2. men * 2 > women : team = women / 2 , men_rest = men - ( women / 2 ) , 여자가 홀수이면 1명이 추가로 남는다. 
	if( men * 2 > women )
	{
		teams = women / 2 ; 
		rest = men - ( women / 2 ) ;
		if( women % 2 == 1 )
			rest += 1 ; 

		while( rest < k ) // 한 팀은 3명 단위, 3명을 rest로 추가해 준다. 
		{
			k -= rest ; 
			rest = 3 ; 
			teams -= 1 ; 
		}
	}

	cout << teams << "\n" ; 
}