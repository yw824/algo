#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://cryptosalamander.tistory.com/15

int main( void ) {
    vector< string > croatian = { "c=" , "c-" , "dz=" , "d-" , "lj" , "nj" , "s=" , "z=" } ;
    int idx ;
    string str ;
    cin >> str ;
    for(int i = 0 ; i < croatian.size() ; i++ )
    {
        while( 1 ){
            idx = str.find( croatian[ i ] ) ;
            if( idx == string::npos )
                break;
            str.replace( idx , croatian[ i ].length() , "#" ) ;
        }
    }
    cout << str.length() ;
}
