#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
  string input, comp;
  cin>>input;
  cin>>comp;

  while(comp.length()>input.length())
  {
    if(comp[comp.length()-1]=='B')
    {
      comp=comp.substr(0,comp.length()-1);
      reverse(comp.begin(),comp.end());
    }
    else // =='A'
      comp=comp.substr(0,comp.length()-1);
  }
  if(comp==input)
  {
    cout<<1;
    return 0;
  }
  cout<<0;
}
