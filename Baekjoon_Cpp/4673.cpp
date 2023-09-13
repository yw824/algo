#include <iostream>
using namespace std;

int cal(int input)
{
  int count=input;
  while(input!=0)
  {
    count+=input%10;
    input=input/10;
  }
  return count;
}

int main(void)
{
  int num[10001]={0,}; // 1부터 사용 - 9901번까지
  for(int i=1 ; i<=9972 ; i++)
    num[cal(i)]=1;
  for(int i=1 ; i<=10000 ; i++)
    if(num[i]==0)
      cout<<i<<endl;
  return 0;
}
