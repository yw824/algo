#include <iostream>
#include <string>
using namespace std;

void pallindrome(string str)
{
  int middle=(str.length()+1)/2; // 홀수든 짝수든 절반값 똑같이 나오게
  for(int i=middle ; i<=str.length()-1 ; i++) // 홀수의 가운데는 비교할 필요가 없음
  {
    if(str[i]!=str[str.length()-i-1])
    {
      cout<<"no\n";
      return;
    }
  }
  cout<<"yes\n";
}

int main(void)
{
  string str=" ";
  cin>>str;
  while(str!="0")
  {
    pallindrome(str);
    cin>>str;
  }
}
