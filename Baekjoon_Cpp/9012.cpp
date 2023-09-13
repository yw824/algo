#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
  string str;
  int arr[50];
  int size; // 스택 배열 현 크기
public:
  Stack(string input):size(0)
  {
    str=input;
    for(int i=0 ; i<50 ; i++)
      arr[i]=0;
  }
  int calc() {
    for(int i=0 ; i<str.length() ; i++)
    {
      if(str[i]=='(')
        arr[size++]=1;
      else if(str[i]==')')
        if(size==0)
          return 0;
        else
          arr[size--]=0;
    }
    if(size==0)
      return 1;
    else
      return 0;
  }
};

int main(void)
{
  int num;
  cin>>num;
  for(int i=0 ; i<num ; i++)
  {
    string str;
    cin>>str;

    Stack s=Stack(str);
    int result=s.calc();
    if(!result)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
  return 0;
}
