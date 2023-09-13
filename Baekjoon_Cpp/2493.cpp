#include <vector>
#include <utility>
#include <iostream>
using namespace std;

bool IsEmpty(int top) { return top==-1; }

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int order;
  cin>>order;
  vector<pair<int,int>> v;
  int top=-1;
  for(int i=0 ; i<order ; i++)
  {
    int temp;
    cin>>temp;
    while(!IsEmpty(top))
    {
      if(v[top].second>temp)
      {
        cout<<v[top].first<<" ";
        break;
      }
      v.pop_back();
      top--;
    }
    if(IsEmpty(top)) cout<<0<<" ";
    v.push_back(make_pair(i+1,temp));
    top++;
  }
}
