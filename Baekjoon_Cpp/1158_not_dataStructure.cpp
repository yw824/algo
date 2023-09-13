//되긴하는데 시간초과 -  Queue 구현 써야함

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main(void)
{
  int n,k;
  cin>>n>>k;
  int order[n];
  int count=0;
  for(int i=0 ; i<n ; i++)
    order[i]=1;
  int index=k-1;
  cout<<'<';
  while(true)
  {
    int temp=0;
    if(order[index]==1)
    {
      cout<<index+1;
      order[index]=0;
      if(count!=n-1) cout<<", ";
      count++;
      if(count==n)
        break;
      while(temp<k)
      {
        index=(index+1)%n;
        if(order[index]==1) temp++;
      }
    }
  }
  cout<<'>'<<endl;
  return 0;
}
