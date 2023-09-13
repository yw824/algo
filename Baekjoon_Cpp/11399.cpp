#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  cin>>n;
  vector<int> v;

  int temp;
  for(int i=0 ; i<n ; i++)
  {
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  int sum[n]={0};
  int total=0;
  for(int i=0 ; i<n ; i++)
  {
    sum[i]=v[i];
    if(i!=0)
      sum[i]+=sum[i-1];
    total+=sum[i];
  }
  cout<<total<<endl;
}
