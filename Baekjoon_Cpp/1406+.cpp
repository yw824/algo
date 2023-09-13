#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
  char data;
  Node* left;
  Node* right;
public:
  Node(char input):data(input){ left=NULL; right=NULL; }
  friend class Editor;
};
class Editor
{
private:
  Node* front;
  Node* current;
public:
  Editor(string str) { front=new Node(str[0]); current=front;
    for(int i=1 ; i<str.length() ; i++)
      Insert(str[i]);
  }
  bool isEmpty() { return current==NULL; }
  void Insert(char c) // 오른쪽으로 붙이기
  {
    Node* temp=new Node(c);
    if(current->right)
    {
      current->right->left=temp;
      temp->right=current->right;
    }
    current->right=temp;
    temp->left=current;
    current=temp;
  }
  void goLeft()  { if(current->left) current=current->left; }
  void goRight() { if(current->right) current=current->right; }
  void Pop()
  {
    if(isEmpty()) return;
    else if(current->left) // left는 있다
    {
      Node* temp=current->left;

      if(current->right) // right마저 있다
      {
        current->left->right=current->right;
        current->right->left=current->left;
      }
      else //없다
        current->left->right=current->left;
      delete current;
      current=temp;
    }
    else if(!current->left) // right는 있고 left는 없다
    {
      Node* temp=current->right;
      current->right->left=current->left;
      delete current;
      current=temp;
    }
  }
  void ShowData()
  {
    Node* temp=front;
    while(temp)
    {
      cout<<temp->data;
      temp=temp->right;
    }
  }
};


int main(void)
{
  string str;
  cin>>str;
  Editor e=Editor(str);
  int num;
  cin>>num;
  char c;
  for(int i=0 ; i<num ; i++)
  {
    cin>>c;
    if(c=='L')
    {
      e.goLeft();
      continue;
    }
    if(c=='D')
    {
      e.goRight();
      continue;
    }
    if(c=='B')
    {
      e.Pop();
      continue;
    }
    if(c=='P')
    {
      cin>>c;
      e.Insert(c);
    }
  }
  e.ShowData();
}
