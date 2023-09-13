#include <iostream>
#include <queue>
using namespace std ;

int alen ;
int blen ;
queue< int > a ;
queue< int > b ;

void Load()
{
  cin >> alen >> blen ;
  int temp ;
  for( int i = 0 ; i < alen ; i++ )
  {
    cin >> temp ;
    a.push( temp ) ;
  }

  for( int i = 0 ; i < blen ; i++ )
  {
    cin >> temp ;
    b.push( temp ) ;
  }
}

void Sort()
{
  int acur , bcur ;
  while( !a.empty() && !b.empty() )
  {
    acur = a.front() ;
    bcur = b.front() ;

    if( acur < bcur )
    {
      cout << acur << " " ;
      a.pop() ;
    }
    else
    {
      cout << bcur << " " ;
      b.pop() ;
    }
  }

  while( !a.empty() )
  {
    acur = a.front() ;
    cout << acur << " " ;
    a.pop() ;
  }
  while( !b.empty() )
  {
    bcur = b.front() ;
    cout << bcur << " " ;
    b.pop() ;
  }
}

int main( void )
{
  cin.tie(0), ios::sync_with_stdio(0);


  Load() ;
  Sort() ;
}
