#include <iostream>
#include <vector>
#include <string>
using namespace std ; 

vector< char > Left ; 
vector< char > Right ;
string str ; 

void ShowData() ; 

void Clear()
{
	/*
	vector< char >::iterator iter ; 
	for( iter = Left.begin() ; iter != Left.end() ; ++iter )
		Left.erase( iter ) ;
	for( iter = Right.begin() ; iter != Right.end() ; ++iter )
		Right.erase( iter ) ;
	*/
	Left.clear();
	Right.clear();
}

void Load()
{
	cin >> str ; 
	int len = (int)str.length() ; 
	// cout << str << "\n" ; 
	// ShowData() ; 

	char c ; 
	for( int i = 0 ; i < len ; i++ )
	{
		if( str[ i ] == '<' )
		{
			if( !Left.size() ) 
				continue ;

			c = Left.back() ; 
			// cout << c << "\n" ; 
			Left.pop_back();
			Right.push_back( c ) ; 
		}
		else if( str[ i ] == '>' )
		{
			if( !Right.size() )
				continue ;

			c = Right.back() ;
			Right.pop_back() ;  
			Left.push_back( c ) ; 	 
		}
		else if( str[ i ] == '-' )
		{
			if( !Left.size() )
				continue ; 
			Left.pop_back() ; 
		}
		else 
			Left.push_back( str[ i ] ) ;

	}
}

void ShowData() 
{
	for( int i = 0 ; i < Left.size() ; i++ )
		cout << Left[ i ] ; 
	for( int i = Right.size() - 1 ; i >= 0 ; i-- )
		cout << Right[ i ] ; 
	cout << "\n" ;
}

int main( void )
{
	int orders ; 
	string str ; 

	cin >> orders ;
	while( orders-- )
	{
		Load() ; 
		ShowData() ; 
		Clear() ; 
	}
}