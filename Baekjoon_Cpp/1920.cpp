#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
// 벡터를 전역변수로 설정 안하면 함수 재귀할 때마다 용량 로드해야 하기 때문에
// -> 용량문제 생긴다.

int BinarySearch(int left, int right,int input)
{
  if(left>right) return 0;
  int middle=(left+right)/2;
  if(v[middle]==input) return 1;
  else if(v[middle]>input)
    return BinarySearch(left,middle-1,input);
  else // if(v[middle]<input)
    return BinarySearch(middle+1,right,input);
}


int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); //cin 속도 향상 위해


  int n;
  cin>>n;
  int temp;
  for(int i=0 ; i<n ; i++)
  {
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end()); // 입력 데이터 정렬까지 완료

  int m;
  cin>>m;
  for(int i=0 ; i<m ; i++)
  {
    cin>>temp;
    cout<<BinarySearch(0,n-1,temp)<<"\n";
  }

}
