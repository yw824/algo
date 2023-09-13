#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력받은 수를 전부 다 입력받아서 저장하면 제한된 8MB 의 메모리 초과
// 숫자를 카운트 해두었다가 표준출력으로 출력만 해두는 방식


int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //위의 세 문장 넣어줘야 함

  int num[10001]={0,};
  int order;
  cin>>order;
  for(int i=0 ; i<order ; i++)
  {
    int data;
    cin>>data;
    num[data]++;
  }
  for(int i=1 ; i<=10000 ; i++)
    for(int j=0 ; j<num[i] ; j++)
      cout<<i<<"\n";
}
