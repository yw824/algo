#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string divided,divisor;
  long long multi1=0,multi2=0;
  cin>>divided>>divisor;
  for(int i=0 ; i<divided.length() ; i++)
    multi1+=(long long)(divided[i]-48);
  for(int i=0 ; i<divisor.length() ; i++)
    multi2+=(long long)(divisor[i]-48);
  cout<<multi1*multi2<<endl;
  return 0;
}

// 만 자릿수라서 int나 long long으로 받으면 안되나보다,,,
// int가 아니라 long long으로 받아야 cout부분에서도 int로 출력 안하고 long long으로 출력하나보다,,,
