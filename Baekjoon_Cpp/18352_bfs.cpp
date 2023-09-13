#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

class Node
{
public:
	int dist ; 
	vector< int > v ; 
};

int n ; // 노드 개수
int k ; // 지정된 거리 
Node* g ; // 그래프 
queue< int > q ; // 큐 

void Load()
{
	int m ; // 간선 개수
	int x ; // 시작 위치 
	cin >> n >> m >> k >> x ; 
	g = new Node[ n + 1 ] ; 
	for( int i = 1 ; i <= n ; ++i )
	{
		g[ i ] = Node() ;
		g[ i ].dist = 10000001 ; // LIM보다 작으면 방문한 것 , 그보다 더 작을 수도 있음 
	}

	int l , r ; 
	for( int i = 0 ; i < m ; ++i )
	{
		cin >> l >> r ; 
		g[ l ].v.push_back( r ) ; // 문제에서 단방향 그래프라고 제시함 
	}

	q.push( x ) ;
	g[ x ].dist = 0 ; 
} 

void BFS()
{
	int cur , pos ; 
	vector< int >::iterator iter ; 
	while( q.size() )
	{
		cur = q.front() ; 
		q.pop() ; 

		if( g[ cur ].dist == k ) // 내가 도작하고 나서 다음 노드들은 어차피 거리가 멀어서 탐색할 필요가 없음 
			continue ; 

		for( iter = g[ cur ].v.begin() ; iter != g[ cur ].v.end() ; ++iter )
		{
			pos = *iter ; 
			if( g[ pos ].dist < g[ cur ].dist + 1 )
				continue ; 
			q.push( pos ) ;
			g[ pos ].dist = g[ cur ].dist + 1 ; 
		}
	}
}

void ShowData()
{
	int cnt = 0 ; 
	for( int i = 1 ; i <= n ; ++i )
		if( g[ i ].dist == k )
		{
			cout << i << '\n' ; 
			cnt += 1 ; 
		}
	if( cnt == 0 )
		cout << -1 ; 
}

int main( void )
{
	Load() ; 
	BFS() ; 
	ShowData() ; 
}
