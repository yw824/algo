#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  vector<int> v;
  int n;
  cin>>n;
  for(int i=0 ; i<n ; i++)
  {
    int data;
    cin>>data;
    v.push_back(data);
  }
  sort(v.begin(),v.end());
  cout<<v[0]*v[v.size()-1]<<"\n";
}

// // 입력받은 다음 정렬하고, 맨처음인덱스 원소와 맨마지막 인덱스원소 곱하기
