#include <iostream>
using namespace std;

class Tree
{
private:
  int* arr;
  int last;
  int capacity;
public: // 루트 인덱스 =1
  Tree(int input):last(0),capacity(input) { arr=new int[input+1]{0}; }
  ~Tree() { delete[] arr; }
  bool isEmpty() { return last==0; }

  void Push(int input)
  {
    arr[++last]=input;
    ExecuteUp(last);
  }
  int selectMaxChild(int index) // leftchild , rightchild 중 더 큰 인덱스 고르기
  {
    return (arr[2*index]>arr[2*index+1]? 2*index : 2*index+1);
  }
  int Pop()
  {
    if(isEmpty()) return 0;
    int temp=arr[1];
    arr[1]=arr[last];
    arr[last--]=0;
    ExecuteDown(1);
    return temp;
  }
  void ExecuteDown(int index)
  {
    while((arr[index]<arr[index*2] || arr[index]<arr[index*2+1]) && index<=last)
    {
      int child=selectMaxChild(index);
      int temp=arr[child];
      arr[child]=arr[index];
      arr[index]=temp;
      index=child;
    }
  }
  void ExecuteUp(int index)
  {
    while(arr[index]>arr[index/2] && index!=1)
    {
      int temp=arr[index/2];
      arr[index/2]=arr[index];
      arr[index]=temp;
      index=index/2;
    }
  }
};

int main(void)
{
  int num;
  cin>>num;
  Tree t=Tree(num);
  for(int i=0 ; i<num ; i++)
  {
    int temp;
    scanf("%d",&temp);
    if(temp==0)
      printf("%d\n",t.Pop());
    else
      t.Push(temp);
  }
}
