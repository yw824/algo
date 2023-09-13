#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 벡터를 클래스 멤버로 여러칸 저장하더라도
// 시간을 줄이는 게 우선 - 아니면 시간초과 뜸

class Note
{
public:
  int order; // 시행 횟수
  vector<int>* arr; // 벡터 배열
  int current;

  Note(int input):order(input),current(0) { arr=new vector<int>[order]; }

  void Execute()
  {
    for( ; current<order ; current++)
    {
      int size;
      cin>>size;
      for(int i=0 ; i<size ; i++)
      {
        int temp;
        cin>>temp;
        arr[current].push_back(temp);
      }
      sort(arr[current].begin(),arr[current].end());

      int test;
      cin>>test;
      while(test--)
      {
        int input;
        cin>>input;
        cout<<BinarySearch(0,arr[current].size()-1,input)<<"\n";
      }
    }
  }
  int BinarySearch(int left, int right, int input)
  {
    int middle;
    while(true)
    {
      if(left>right) return 0;
      middle=(left+right)/2;
      if(arr[current][middle]==input) return 1;
      else if(arr[current][middle]<input)
        left=middle+1;
      else
        right=middle-1;
    }
  }
};

int BinarySearch(vector<int> arr, int left, int right, int input)
{
  int middle;
  while(true)
  {
    if(left>right)
      return 0;
    middle=(left+right)/2;
    if(arr[middle]==input)
      return 1;
    else if(arr[middle]<input)
    {
      left=middle+1;
      continue;
    }
    else // arr[middle]>input
      right=middle-1;
  }
}

int main(void)

{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int order;
  cin>>order;

  Note n=Note(order);
  n.Execute();
}
