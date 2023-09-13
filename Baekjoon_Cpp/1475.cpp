#include <iostream>
using namespace std;


int main(void)
{
  int num[10]={0,}; // 각각 들어가는 숫자들
  int input;
  cin>>input;
  int count=0;
  while(true)
  {
    if(input==0 && count==0 )
    {
      num[0]++;
      break;
    }
    else if( input==0 && count==1 )
      break;
    else
    {
      count=1;
      num[input%10]++;
      input=input/10;
    }
  }
  count=0;
  for(int i=0 ; i<10 ; i++)
  {
    int temp=(num[6]+num[9]+1)/2;
    if(i!=6 && i!=9 && count<num[i])
    {
      count=num[i];
    }
    if(temp>count)
      count=temp;
  }
  cout<<count<<endl;
  return 0;
}
