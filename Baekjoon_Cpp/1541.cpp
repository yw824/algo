#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
  int* stack;
  int top;
  int count;
  bool isMinus;

  Stack(int input):top(-1),count(0),isMinus(false) { stack=new int[input]; }
  ~Stack() { delete[] stack; }

  bool isEmpty() { return top==-1; }
  int Cal()
  {
    for(int i=0 ; i<str.length() ; i++)
    {
      int temp=0;


    }
    return count;
  }
  void clean()
  {
    for(int i=top ; top>-1 ; top--)
      count+=stack[top];
  }

};

int main(void)
{
  string str;
  cin>>str;
  Stack s=Stack(str.length());
  cout<<s.Cal();
  s.~Stack();
}
