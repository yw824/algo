//stack 구현
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
  int* arr;
  int Size;
  int capacity;
public:
  Stack(int input):Size(0), capacity(input)
  { arr=new int[input]; }

  int empty()
  {
    if(Size==0) return 1;
    return 0;
  }

  void push(int input)
  {
    if(Size==capacity) return;
    arr[Size++]=input;
  }

  int top() {
    if(Size==0) return -1;
    return arr[Size-1];
  }

  int size()
  {
    return Size;
  }

  int pop()
  {
    if(Size==0) return -1;
    int temp=arr[Size-1];
    Size--;
    return temp;
  }

  ~Stack() {delete[] arr; }
};

int main(void)
{
  int temp;
  cin>>temp;
  Stack s=Stack(temp);
  for(int i=0 ; i<temp ; i++)
  {
    string str;
    cin>>str;
    if(str=="top")
      cout<<s.top()<<endl;
    else if(str=="pop")
      cout<<s.pop()<<endl;
    else if(str=="empty")
      cout<<s.empty()<<endl;
    else if(str=="size")
      cout<<s.size()<<endl;
    else if(str=="push")
    {
      int temp;
      cin>>temp;
      s.push(temp);
    }
    else
      cout<<"ERROR"<<endl;
  }
  return 0;
}
