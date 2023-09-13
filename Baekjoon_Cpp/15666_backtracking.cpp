#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std ; 

// https://cherishvert.tistory.com/16

int n ; // 입력되는 숫자 개수 
int m ; // 최대 m개 
bool* avail ; // 존재하는 독립적인 숫자 체크 배열 ( 1 <= 입력 <= 10000 )

int total ; // 총 개수 
int* w ; 
vector< int > v ; 

void Load()
{
	avail = new bool[ 100001 ]{ false } ; 
	cin >> n >> m ; 

	int temp ; 
	total = 0 ; 
	for( int i = 0 ; i < n ; ++i )
	{
		cin >> temp ; 
		if( avail[ temp ] )
			continue ; 

		avail[ temp ] = true ;
		++total ; 
	}

	w = new int[ total ] ; 
	temp = 0 ; 

	for( int i = 0 ; i <= 100001 ; ++i )
		if( avail[ i ] )
		{ 
			w[ temp++ ] = i ; 
		}
}

// 백트래킹 

void Print()
{
	vector< int >::iterator iter ;
	for( iter = v.begin() ; iter != v.end() ; ++iter )
		cout << w[ *iter ] << " " ;
	cout << "\n" ;  
}

int getIndex( int input )
{
	for( int i = 0 ; i < total ; ++i )
		if( w[ i ] == input )
			return i ; 
	return -1 ; 
}

void Next_Permutation( int cnt )
{
	if( cnt == m )
	{
		Print() ; 
		return ; 	
	}

	int stand ; 
	if( !v.size() )
		stand = 0 ; 
	else
		stand = getIndex( w[ v.back() ] ) ;

	for( int i = stand ; i < total ; ++i )
	{
		v.push_back( i ) ;
		Next_Permutation( cnt + 1 ) ;
		v.pop_back() ; 
	}
}

int main( void )
{
	Load() ; 
	Next_Permutation( 0 ) ;
}