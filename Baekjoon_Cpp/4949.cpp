#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
  char* stack;
  string str;
  int top;
public:
  Stack(string input):top(-1),str(input) { stack=new char[100]; }
  ~Stack() { delete stack; }
  bool isEmpty() { return top==-1; }
  string getString() { return str; }
  void Execute()
  {
    for(int i=0 ; i<str.length() ; i++)
    {
      if(str[i]=='(' || str[i]=='[')
      {
        stack[++top]=str[i];
        //cout<<str[i]<<" , top: "<<top<<endl;
      }
      else if(str[i]==')')
      {
        if(isEmpty() || stack[top]!='(')
        {
          cout<<"no"<<endl;
          return;
        }
        else if(stack[top]=='(')
          stack[top--]='\0';
      }
      else if(str[i]==']')
      {
        if(isEmpty() || stack[top]!='[')
        {
          cout<<"no"<<endl;
          return;
        }
        else if(stack[top]=='[')
          stack[top--]='\0';
      }
    }
    if(isEmpty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
};

int main(void)
{
  while(true)
  {
    string str;
    getline(cin,str);
    if(str==".") break;
    Stack* s=new Stack(str);
    s->Execute();
    s->~Stack();
    str="";
  }
}

// 빈례: (])
