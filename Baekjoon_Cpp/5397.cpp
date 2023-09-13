#include <iostream>
#include <string>
using namespace std;

class Stack;
class Node
{
private:
  char data;
  Node* left;
  Node* right;
public:
  Node(char input='\0'):data(input) { left=NULL; right=NULL; }
  ~Node() { delete left; delete right; }
  friend class Stack;
};

class Stack
{
private:
  Node* top;
  Node* current;
public:
  Stack() { top=new Node(); current=top; } // 맨 밑 데이터 '\0'인 더미노드 생성
  ~Stack() { delete top; delete current; }

  void Push(char input)
  {
    Node* temp=new Node(input);
    Node* Left=current->left;
    Node* Right=current->right;
    Left->right=temp;
    Right->left=temp;
    temp->right=Right;
    temp->left=Left;
    current=temp;
  }
  void Pop()
  {
    Node* Left=current->left;
    Node* Right=current->right;
    Left->right=current->right;
    Right->left=current->left;
    current->~Node();
    current=Left;
  }
  void goLeft()
  {
    if(current->left!=NULL)
      current=current->left;
  }
  void goRight()
  {
    if(current->right!=NULL)
      current=current->right;
  }
  void ShowData()
  {
    Node* temp=top->right;
    if(temp!=NULL)
    {
      cout<<temp->data;
      temp=temp->right;
    }
  }
};


int main(void)
{
  int num;
  cin>>num;

  for(int i=0 ; i<num ; i++)
  {
    Stack* s=new Stack();
    string str;
    cin>>str;
    for(int j=0 ; j<str.length() ; j++)
      s->Push(str[i]);
    s->ShowData();
    s->~Stack();
  }

}
