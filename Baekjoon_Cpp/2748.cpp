#include <iostream>
using namespace std;

// 답이 int형보다 더 큰 값이 나올 수 있다.
// long long으로 변수 저장할 칸 부여해야 한다.

int main(void)
{
  int n;
  cin>>n;
  long long fibo1=0;
  long long fibo2=1;
  if(n==0 || n==1)
  {
    cout<<n;
    return 0;
  }
  for(int i=2 ; i<=n ; i++)
  {
    long long temp=fibo1+fibo2;
    fibo1=fibo2;
    fibo2=temp;
  }
  cout<<fibo2;

}
