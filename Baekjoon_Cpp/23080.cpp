#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
  int n;
  cin>>n;
  string str;
  cin>>str;

  for(int i=0 ; i<str.length() ; i+=n)
    cout<<str[i];
  cout<<"\n";
}
