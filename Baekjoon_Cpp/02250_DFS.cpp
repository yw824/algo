#include <iostream>
using namespace std ;

class Node
{
public:
	bool visited ; 
	int left ; 
	int right ; 
	int width ; 
	int depth ; 
	int parent ;

	Node()
	{
		visited = false ; 
		left = -1 ; 
		right = -1 ; 
		width = 0 ; 
		depth = 0 ; 
		parent = 0 ; 
	}
};

Node* tree ; 
int n ; // nodes in tree
int deepest ; 
int col ;
int** w ;
int ans ; 
int line ; 
int start ; 

void Load()
{
	cin >> n ;
	tree = new Node[ n + 1 ] ;
	for( int i = 1 ; i <= n ; i++ )
		tree[ i ] = Node() ; 

	int index , left , right ;  
	for( int i = 1 ; i <= n ; i++ )
	{

		cin >> index >> left >> right ; 

		tree[ index ].left = left ; 
		if( left != -1 )
			tree[ left ].parent = index ; 
		
		tree[ index ].right = right ;
		if( right != -1 )
			tree[ right ].parent = index ;
	}

	deepest = 0 ; 
	col = 1 ; 
	ans = 0 ; 
	line = 1 ;

	for( int i = 1 ; i <= n ; i++ )
		if( tree[ i ].parent == 0 )
		{
			start = i ; 
			break ; 
		} 
	// cout << "start : " << start << "\n" ; 
}

void Inorder_Traverse( int index , int depth )
{
	if( tree[ index ].visited )
		return ; 

	// left child node
	if( tree[ index ].left != -1 && !tree[ tree[ index ].left ].visited )
		Inorder_Traverse( tree[ index ].left , depth + 1 ) ;

	// current node
	tree[ index ].depth = depth ; 
	if( depth > deepest ) deepest = depth ; 

	tree[ index ].width = col++ ; 
	tree[ index ].visited = true ; 

	// right child node
	if( tree[ index ].right != -1 && !tree[ tree[ index ].right ].visited )
		Inorder_Traverse( tree[ index ].right , depth + 1 ) ;
}

void ShowData()
{
	for( int i = 1 ; i <= n ; i++ )
		cout << i << " " << tree[ i ].width << " " << tree[ i ].depth << "\n" ; 
} 

void LoadMatrix() 
{
	deepest++ ; 
	w = new int*[ deepest ] ; 
	for( int i = 0 ; i < deepest ; i++ )
		w[ i ] = new int[ col ]{ 0 } ; 

	for( int i = 1 ; i <= n ; i++ )
		w[ tree[ i ].depth ][ tree[ i ].width ] = i ; 
}

void ShowData2()
{
	for( int i = 1 ; i < deepest ; i++ )
	{
		for( int j = 1 ; j < col ; j++ )
			cout << w[ i ][ j ] << " " ; 
		cout << "\n" ; 
	}
}

void Check()
{
	int front , back , temp ; 
	for( int i = 1 ; i < deepest ; i++ )
	{
		front = back = -1 ; 
		for( int j = 1 ; j < col ; j++ )
			if( w[ i ][ j ] )
				if( front == -1 )
					front = j ; 
				else
					back = j ; 

		if( back == -1 )
			temp = 1 ; 
		else
			temp = back - front + 1 ; 

		if( temp > ans ) 
		{
			ans = temp ;
			line = i ; 
		}
	}
}

int main( void )
{
	Load() ; 

	// never start from 1 ( you have to figure out which one is the root )
	Inorder_Traverse( start , 1 ) ;
	// ShowData() ; 
	// cout << "col : " << col << " , depth : " << deepest << "\n" ; 

	LoadMatrix() ; 
	// ShowData2() ; 
	Check() ; 
	cout << line << " " << ans << "\n" ;
}