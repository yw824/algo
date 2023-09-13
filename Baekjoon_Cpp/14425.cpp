#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main(void)
{
  int n,m1;
  cin>>n>>m1;
  map<string,int> m;
  while(n--)
  {
    string str;
    cin>>str;
    m.insert(pair<string,int>(str,0));
  }
  int count=0;
  while(m1--)
  {
    string str;
    cin>>str;
    if(m.find(str)!=m.end())
      count++;
  }
  cout<<count;
}
