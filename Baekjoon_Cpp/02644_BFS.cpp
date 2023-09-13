#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

class Family ;
class Node
{
public:
  int val ; // 시작하는 노드로부터의 관계 값
  vector<int> kinship ; // 촌수

  Node():val( -1 ) { }
  friend class Family ;
} ;

class Family
{
public:
  int n ;
  int start ;
  int end ;
  Node** fam ;
  queue<int> q ;

  void Load()
  {
    cin >> n ;
    fam = new Node*[ n + 1 ] ;
    for( int i = 1 ; i <= n ; i++ )
      fam[ i ] = new Node() ;

    cin >> start >> end ;

    int relation ;
    cin >> relation ;
    int par , son ;
    while( relation-- )
    {
      cin >> par >> son ;
      fam[ par ] -> kinship.push_back( son ) ;
      fam[ son ] -> kinship.push_back( par ) ;
    }
  }

  void ShowData()
  {
    for( int i = 1 ; i <= n ; i++ )
    {
      printf("%d : " , i ) ;
      for(vector<int>::iterator iter = fam[i]->kinship.begin() ; iter != fam[i]->kinship.end() ; ++iter )
        cout << *iter << " " ;
      cout << "\n" ;
    }
  }

  void BFS_Init()
  {
    q.push(start);
    fam[start]->val = 0 ;
    BFS() ;
  }

  void BFS()
  {
    vector<int>::iterator iter ;
    while( !q.empty() )
    {
      for(iter = fam[q.front()]->kinship.begin() ; iter != fam[q.front()]->kinship.end() ; ++iter )
      {
        // printf("%d : %d\n" , *iter , fam[*iter]->val) ;
        if( fam[*iter]->val == -1 )
        {
          fam[*iter]->val = fam[q.front()]->val + 1 ;
          q.push(*iter);
        }
      }
      q.pop();
    }
  }

  void getFinish()
  {
    cout << fam[end]->val ;
  }
};

int main( void )
{
  Family f ;
  f.Load() ;
  // f.ShowData() ; - 입력까지 완료

  f.BFS_Init() ;
  f.getFinish() ;
}
