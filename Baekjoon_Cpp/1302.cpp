#include <iostream>
#include <map>
using namespace std;

int main(void)
{
  map<string,int> m;
  int test;
  cin>>test;
  string name;
  string maxindex;
  int max=0;
  for(int i=0 ; i<test ; i++)
  {
    cin>>name;
    if(m.find(name)==m.end())
      m[name]=1;
    else
      m[name]++;
  }
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) // auto 형으로도 사용 가능
  {
    //cout << it->first << ' ' << it->second << '\n';
    if(it->second>max)
    {
      maxindex=it->first;
      max=it->second;
    }
  }
  cout<<maxindex<<endl;
}
