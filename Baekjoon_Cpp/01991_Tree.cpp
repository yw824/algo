#include <iostream>
using namespace std ;

class Tree ;
class Node
{
  char val ;
  int visited ;
  char left ;
  char right ;
  Node( char valI , char leftI , char rightI ): visited( 0 )
  {
    val = valI ;
    left = leftI ;
    right = rightI ;
  }
  friend class Tree ;
};

// 아스키코드 A : 65
class Tree
{
public:
  int n ; // 배열 크기
  Node** arr ;

  void Load()
  {
    cin >> n ;
    arr = new Node*[ n + 1 ]{ NULL } ;

    char val , left , right ;
    for( int i = 0 ; i < n ; i++ )
    {
      cin >> val >> left >> right ;
      arr[ val - 65 + 1 ] = new Node( val , left , right ) ;
    }
  }

  void ShowData()
  {
    for( int i = 1 ; i <= n ; i++ )
      printf("%c(visited : %d) -> %c , %c \n" , arr[ i ]->val , arr[ i ]->visited, arr[ i ]->left , arr[ i ]->right ) ;
  }

  void Init()
  {
    cout << "\n" ;
    for( int i = 1 ; i <= n ; i++ )
      arr[ i ]->visited = 0 ;
  }

  void Pre( int curr )
  {
    if( !arr[ curr ]->visited )
    {
      cout << arr[ curr ]->val ;
      arr[ curr ]->visited = 1 ;
    }
    if( arr[ curr ]->left != '.' )
      if( !arr[ arr[ curr ] -> left - 65 + 1 ]->visited )
        Pre( arr[ curr ]->left - 65 + 1 ) ;
    if( arr[ curr ]->right != '.' )
      if( !arr[ arr[ curr ] -> right - 65 + 1 ]->visited )
        Pre( arr[ curr ]->right - 65 + 1 ) ;
  }

  void Mid( int curr )
  {
    if( arr[ curr ]->left != '.' )
      if( !arr[ arr[ curr ] -> left - 65 + 1 ]->visited )
        Mid( arr[ curr ]->left - 65 + 1 ) ;
    if( !arr[ curr ]->visited )
    {
      cout << arr[ curr ]->val ;
      arr[ curr ]->visited = 1 ;
    }
    if( arr[ curr ]->right != '.' )
      if( !arr[ arr[ curr ] -> right - 65 + 1 ]->visited )
        Mid( arr[ curr ]->right - 65 + 1 ) ;
  }

  void Post( int curr )
  {
    if( arr[ curr ]->left != '.' )
      if( !arr[ arr[ curr ] -> left - 65 + 1 ]->visited )
        Post( arr[ curr ]->left - 65 + 1 ) ;
    if( arr[ curr ]->right != '.' )
      if( !arr[ arr[ curr ] -> right - 65 + 1 ]->visited )
        Post( arr[ curr ]->right - 65 + 1 ) ;
    if( !arr[ curr ]->visited )
    {
      cout << arr[ curr ]->val ;
      arr[ curr ]->visited = 1 ;
    }
  }
};

int main( void )
{
  Tree t ;
  t.Load() ;
  // t.ShowData() ; // 입력까지 완료
  t.Pre( 1 );
  t.Init() ;
  t.Mid( 1 );
  t.Init() ;
  t.Post( 1 );
}
