#include <iostream>
#include <string>
using namespace std;

class Bracket
{
public:
  string str; // 입력받는 문자열
  char* bracket; // 스택 배열
  int top;  // 스택 배열 제일 위 인덱스
  int* count;  //결과값
  int level; // 결과값 층수

  Bracket(string input):top(-1),level(0)
  {
    str=input;
    count=new int[str.length()+1]{0};
    bracket=new char[str.length()];
  }
  int cal(int index)
  {
    if(str[index]=='[' || str[index]=='(')
    {
      bracket[++top]=str[index];
      level++;
    }
    else if(str[index]==')')
    {
        if(bracket[top]==']' || top==-1)
          return -1;
        if(count[level+1]==0)
          count[level]+=2;
        else
          count[level]+=(count[level+1])*2;
        count[level+1]=0;
        top--;
        level--;
    }
    else if(str[index]==']')
    {
      if(bracket[top]==')' || top==-1)
        return -1;
      if(count[level+1]==0)
        count[level]+=3;
      else
        count[level]+=(count[level+1])*3;
      count[level+1]=0;
      top--;
      level--;
    }
    return 0;
  }

};

int main(void)
{
  string str;
  cin>>str;
  Bracket b=Bracket(str);
  int temp=0;
  for(int i=0 ; i<b.str.length() ; i++)
  {
    int result=b.cal(i);
    if(result==-1)
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<b.count[0]<<endl;
}
