#include <iostream>
using namespace std;

int main(void)
{
  int num;
  cin>>num;
  num=1000-num;
  int count=0;

  count+=num/500;
  num=num%500;

  count+=num/100;
  num=num%100;

  count+=num/50;
  num=num%50;

  count+=num/10;
  num=num%10;

  count+=num/5;
  num=num%5;
  count+=num/1;

  cout<<count;
}
