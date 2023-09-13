#include <iostream>
#include <string>
using namespace std ;
 
int main( void )
{
    int cnt ;
    string str ; 
    int len ; 
    int i ; 
    while( true )
    {
        cnt = 0 ; 
        getline( cin , str ) ;
        len = ( int )str.length() ; 
        if( !str.compare("#") )
            break ;
        for( i = 0 ; i < len ; ++i )
        {
            if( str[ i ] == 'a' || str[ i ] == 'e' || str[ i ] == 'i' || str[ i ] == 'o' || str[ i ] == 'u' )
            {
                cnt += 1 ; 
                continue ; 
            }
            if( str[ i ] == 'A' || str[ i ] == 'E' || str[ i ] == 'I' || str[ i ] == 'O' || str[ i ] == 'U' )
            {
                cnt += 1 ; 
                continue ; 
            }
        }
        cout << cnt << "\n" ; 
    }
}