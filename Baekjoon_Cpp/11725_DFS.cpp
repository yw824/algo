#include <iostream>
#include <vector>
using namespace std ;

// DFS
// 2차원 배열로 평소대로 정리하면 시간초과 발생
// 아마도 입력값이 100000만개일 때도 있는 것 같다.
// 그래서 벡터 사용 위해 노드 및 트리 클래스로 구현

class Tree;
class Node
{
public:
  int parent ;
  vector< int > link ;

  Node( int input ): parent( input ) {}
  friend class Tree ;
};

class Tree
{
public:
  int n ; // 정점 개수
  Node** tree ; // 노드 트리
  void LoadMatrix()
  {
    cin >> n ;
    tree = new Node*[ n + 1 ] ;
    for( int i = 1 ; i <= n ; i++ )
      tree[ i ] = new Node( 0 ) ;

    int x ; int y ;
    for( int i = 1 ; i < n ; i++ )
    {
      cin >> x >> y ;
      tree[ x ]->link . push_back( y ) ;
      tree[ y ]->link . push_back( x ) ;
    }
  }

  void DFS( int x , int parent )
  {
    tree[ x ]-> parent = parent ;
    for( vector<int>::iterator iter = tree[ x ] -> link.begin() ; iter != tree[ x ] -> link.end() ; ++iter )
      if( !tree[ *iter ]->parent )
        DFS( *iter , x ) ;
  }

  void ShowData()
  {
    for( int i = 2 ; i <= n ; i++ )
     cout << tree[ i ] -> parent << "\n" ;
  }
};

int main( void )
{
  Tree t ;
  t.LoadMatrix() ;

  t.DFS( 1 , 1 ) ;
  t.ShowData() ;
}
