#include <iostream>
#include <string>
using namespace std;

bool Checker(string str)
{
  int alpha[2][26]={0};
  int count=0;
  for(int i=0 ; i<str.length() ; i++)
  {
    if(alpha[1][(int)(str[i]-97)]==1)
      return false;
    count++;
    if(i!=str.length() && str[i]!=str[i+1])
    {
      alpha[0][(int)(str[i]-97)]=count;
      alpha[1][(int)(str[i]-97)]=1;
      count=0;
    }
    else if(i==str.length()-1 )
    {
      alpha[0][i]=count;
      alpha[1][i]=1;
    }
  }
  return true;
}

int main(void)
{
  string str;
  int Try, count=0;
  cin>>Try;
  for(int i=0 ; i<Try ; i++)
  {
    cin>>str;
    if(Checker(str))
      count++;
  }
  cout<<count;
  return 0;
}
