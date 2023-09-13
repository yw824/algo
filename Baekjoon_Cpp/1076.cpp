#include <iostream>
using namespace std;

int main(void)
{
  string color[10]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
  long long multipl[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

  string str1,str2,str3;
  cin>>str1;
  cin>>str2;
  cin>>str3;
  long long result[3]={0,0,0};
  for(int i=0 ; i<10 ; i++)
  {
    if(str1==color[i])
      result[0]=i;
    if(str2==color[i])
      result[1]=i;
    if(str3==color[i])
      result[2]=multipl[i];
  }
  cout<<(result[0]*10+result[1])*result[2]<<endl;
  return 0;
}
 // int로 놓은 다음에 곱하면 int의 범위를 넘어서는 값이 나온다. 그래서 long long으로 설정해야 한다.
