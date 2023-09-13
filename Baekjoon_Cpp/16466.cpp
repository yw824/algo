#include <iostream>
using namespace std;

int main(void)
{
  int arr[10000001]={0};
  int num;
  cin>>num;
  int temp;
  for(int i=0 ; i<num ; i++)
  {
    cin>>temp;
    arr[temp]=1;
  }
  for(int i=1 ; ; i++)
  {
    if(arr[i]==0)
    {
      cout<<i<<endl;
      break;
    }
  }
}
