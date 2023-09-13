#include <iostream>
#include <vector>
using namespace std ;

vector< int > l ; 
vector< int > r ; 
int n ; 
int* w ; 

void Load()
{
	cin >> n ; 
	w = new int[ n + 1 ] ;
	for( int i = 1 ; i <= n ; ++i )
		cin >> w[ i ] ; 
}

void Execute()
{
	int cnt ; 
	for( int i = 1 ; i <= n ; ++i )
	{
		cnt = w[ i ] ; 
		while( cnt > 0 )
		{
			r.push_back( l.back() ) ;
			l.pop_back() ; 
			cnt -= 1 ; 
		}

		l.push_back( i ) ;
		while( r.size() )
		{
			l.push_back( r.back() ) ;
			r.pop_back() ; 
		}
	}
}

int main( void )
{
	Load() ; 
	Execute() ; 
	vector< int >::iterator iter ; 
	for( iter = l.begin() ; iter != l.end() ; ++iter )
		cout << *iter << " " ;
	cout << "\n" ; 
}