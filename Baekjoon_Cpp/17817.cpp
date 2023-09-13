#include <iostream>
using namespace std;

int Queri(int input)
{
  int sum=0;
  while(input!=0)
  {
    sum+=input%10;
    input=input/10;
  }
  return sum;
}

int main(void)
{
  int order;
  cin>>order;
  for(int i=0 ; i<order ; i++)
  {
    int start,end;
    cin>>start>>end;
    int sum=0;
    for(int j=start ; j<=end ; j++)
      sum+=Queri(j);
    cout<<sum<<"\n";
  }
}
