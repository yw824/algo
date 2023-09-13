#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int convert(char* str)
{
  int temp=0;
  int count=1;
  for(int i=2 ; i>=0 ; i--)
  {
    i f(str[i]!='\0')
      temp+=(str[i]-48)*count;
    count*=2;
  }
  return temp;
}
int main(void)
{
  string str1;
  cin>>str1;
  int result=0, count=1;
  for(int i=str1.length()-1 ; i>=0 ; i-=3)
  {
    char str2[3];
    if(i==0)
    {
      str2[0]='\0';
      str2[1]='\0';
      str2[2]=str1[i];
    }
    else if(i==1)
    {
      str2[0]='\0';
      str2[1]=str1[0];
      str2[2]=str1[1];
    }
    else
    {
      str2[0]=str1[i-2];
      str2[1]=str1[i-1];
      str2[2]=str1[i];
    }
    result+=convert(str2)*count;
    count*=8;
  }
  cout<<result<<endl;
  return 0;
}



/*
맨 처음 풀이 // 백만자리단위 수가 입력되는데, 2^(1,000,000-1) 은 long long에도 입력 불가능
 -> 8진수 단위로 끊어서 생각해야함

int convert(string str)
{
  int temp=0;
  int count=1;
  for(int i=str.length()-1 ; i>=0 ; i--)
  {
    temp+=(str[i]-48)*count;
    count*=2;
  }
  return temp;
}

int main(void)
{
  string str; // 2진수 문자열로 입력
  cin>>str;
  int result=convert(str);
  printf("%o",result);
  return 0;
}

*/
