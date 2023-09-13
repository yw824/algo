#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  vector<int> v;
  int order;
  cin>>order;
  while(order--)
  {
    int num;
    cin>>num;
    v.push_back(num);
  }
  sort(v.begin(),v.end());

  for(int i=0 ; i<v.size() ; i++)
    cout<<v[i]<<"\n";
}
