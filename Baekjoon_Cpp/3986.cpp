#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
  string str;
  char* stack;
  int top;
  Stack(string input):top(-1), str(input)
  {    stack=new char[str.length()];  }
  ~Stack() { delete[] stack; }

  bool isEmpty() { return top==-1; }
  int Counter() {
    for(int i=0 ; i<str.length() ; i++)
    {
      if(isEmpty())  stack[++top]=str[i];
      else if(str[i]!=stack[top]) stack[++top]=str[i];
      else
      {
        top--;
      }
    }
    if(isEmpty()) return 1;
    return 0;
  }
};

int main(void)
{
  int input;
  cin>>input;
  int count=0;
  for(int i=0 ; i<input ; i++)
  {
    string str;
    cin>>str;
    Stack* s=new Stack(str);
    if(s->Counter()) count++;
    s->~Stack();
  }
  cout<<count<<endl;

  return 0;
}
