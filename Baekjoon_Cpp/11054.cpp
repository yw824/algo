#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> v) // 최대인 인덱스 구함
{
  int minindex=0;
  for(int i=0 ; i<v.size ; i++)
    if(v[i]>v[minindex])
      minindex=i;
  return minindex;
}

int main(void)
{
  int n;
  cin>>n;
  vector<int> v;
  for(int i=0 ; i<n ; i++)
  {
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  int index=max(v);

}
