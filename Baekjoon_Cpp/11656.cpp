#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
  vector<string> v;
  string str;
  cin>>str;

  for(int i=0 ; i<str.length() ; i++)
    v.push_back(str.substr(i));
  sort(v.begin(), v.end());
  for(vector<string>::iterator iter=v.begin() ; iter!=v.end() ; ++iter)
    cout<<(*iter)<<"\n";
}
