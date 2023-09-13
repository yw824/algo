#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int order;
  cin>>order;

  if (!order) //n이 0이면 0출력 후 종료
  {
    cout <<0;
    return 0;
  }

  vector<int> v;

  while(order--)
  {
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());

  int num=(int)((v.size()/100.0)*15+0.5);
  int total=0;
  for(int i=num ; i<v.size()-num ; i++)
    total+=v[i];
  total=(int)((float)total/(v.size()-2*num)+0.5);
  cout<<total;
}
