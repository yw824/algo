#include <iostream>
using namespace std;

int main(void)
{
  int test;
  cin>>test;
  int num[100001]={0};
  int max=-1;
  for(int i=0 ; i<test ; i++)
  {
    int temp;
    cin>>temp;
    num[temp]++;
  }
  for(int i=0 ; i<100001 ; i++)
  {
    if(num[i]==i)
      if(i>max)
        max=i;
  }
  cout<<max<<endl;
}
