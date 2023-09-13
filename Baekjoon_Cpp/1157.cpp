#include <iostream>
using namespace std;

int main(void)
{
  int count[26],max=0;
  char maxIdx;
  for(int i=0 ; i<26 ; i++)
    count[i]=0;
  string str;
  cin>>str;
  for(int i=0 ; i<str.length() ; i++)
  {
    if(str[i]<97)
      count[str[i]-65]++;
    else
      count[str[i]-97]++;
  }
  for(int i=0 ; i<26 ; i++)
  {
    if(max<count[i])
    {
      maxIdx=(char)(i+65);
      max=count[i];
    }
    else if(max==count[i])
      maxIdx='?';
  }
  cout<<maxIdx<<endl;
  return 0;
}
