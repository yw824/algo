#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str;
  cin>>str;

  for(int i=str.length()/2 ; i<=str.length()-1 ; i++)
    if(str[i]!=str[str.length()-i-1])
    {
      cout<<0;
      return 0;
    }
  cout<<1;
  return 0;
}
