#include <iostream>
#include <utility>
#include <map>
using namespace std;

int main(void)
{
  map<string, string> ma;
  int n,m;
  cin>>n>>m;
  while(n--)
  {
    string str1,str2;
    cin>>str1>>str2;
    ma.insert(pair<string,string>(str1,str2));
  }
  while(m--)
  {
    string str1;
    cin>>str1;
    cout<<ma[str1]<<"\n";
  }
}
