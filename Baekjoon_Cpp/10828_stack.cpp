#include <iostream>
#include <vector>

#include <string>
using namespace std ;

vector< int > v ; 
int orders ; 

int main( void )
{
	string order ;
	int num ; 

	cin >> orders ; 
	while( orders-- )
	{
		cin >> order ;

		if( !order.compare("push") ) // push
		{

			cin >> num ; 
			v.push_back( num ) ; 
		}
		else if( !order.compare("top") ) // top
		{
			if( !v.size() )
			{
				cout << -1 << "\n" ; 
				continue ; 
			}
			cout << v.back() << "\n" ; 
		}
		else if( !order.compare("pop") ) // pop
		{
			if( !v.size() )
			{
				cout << -1 << "\n" ; 
				continue ; 
			}
			cout << v.back() << "\n" ; 
			v.pop_back() ; 
		}
		else if( !order.compare("empty") ) // empty
		{
			if( !v.size() )
			{
				cout << "1" << "\n" ; 
				continue ; 
			}
			cout << "0" << "\n" ; 
			continue ; 
		}
		else if( !order.compare("size") ) // size
			cout << v.size() << "\n" ; 

	}
}