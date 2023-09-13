#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 이진탐색 안하고, 일일이 비교하게 되면 시간초과걸림

vector<string> v;
vector<string> temp;

bool BinarySearch(int left, int right, string input)
{
  if(left>right) return false;
  int middle=(left+right)/2;
  if(!v[middle].compare(input)) return true;
  else if(v[middle].compare(input)<0) return BinarySearch(middle+1,right,input);
  else return BinarySearch(left,middle-1,input);
}

int main(void)
{
  int n,m;
  cin>>n>>m;
  string str;

  while(n--)
  {
    cin>>str;
    v.push_back(str);
  }
  sort(v.begin(),v.end());

  while(m--)
  {
    cin>>str;
    if(BinarySearch(0,v.size()-1,str)) temp.push_back(str);
  }
  sort(temp.begin(),temp.end());
  cout<<temp.size()<<"\n";
  for(vector<string>::iterator iter=temp.begin() ; iter!=temp.end() ; ++iter)
    cout<<(*iter)<<"\n";
}
