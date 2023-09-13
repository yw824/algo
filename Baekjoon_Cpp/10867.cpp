#include <iostream>
using namespace std;

int main(void)
{
  int num[1001]={0};
  int minus[1001]={0};
  int order;
  cin>>order;
  int test[order]={0};
  for(int i=0 ; i<order ; i++)
  {
    cin>>test[i];
    if(test[i]<0)
      minus[test[i]*(-1)]++;
    else
      num[test[i]]++;
  }
  for(int i=1000 ; i>=0 ; i--)
    if(minus[i])
      cout<<i*(-1)<<" ";
  for(int i=0 ; i<1001 ; i++)
    if(num[i])
      cout<<i<<" ";
}
