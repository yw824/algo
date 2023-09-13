#include <iostream>
using namespace std ; 

int n ; // 5 <= n <= 40
int* w ;

void Load()
{
	cin >> n ; 
	w = new int[ n + 1 ]{ 0 } ; 
	w[ 1 ] = 1 ; 
	w[ 2 ] = 1 ; 
}

// 재귀 호출 : 재귀 호출하여 최종 fib(2) 와 fib(1) 호출 횟수의 합 
// DP 횟수 : 3부터 n까지의 iteration 횟수 = n - 3 + 1 
void DP()
{
	for( int i = 3 ; i <= n ; ++i )
		w[ i ] = w[ i - 1 ] + w[ i - 2 ] ;
}


int main( void )
{
	Load() ; 
	DP() ; 
	cout << w[ n ] << " " << ( n - 2 ) << "\n" ;  
}