//Queue구현
#include <iostream>
using namespace std;

class Queue
{
private:
  int* arr;
  int Front;
  int Back;
  int capacity;
public:
  Queue(int input):Front(-1), Back(-1),capacity(input)
  {
    arr=new int[input];
    for(int i=0 ; i<capacity ; i++)
      arr[i]=0;
  }

  int empty()
  {
    if(Front==Back) return 1;
    return 0;
  }

  int front()
  {
    if(empty()) return -1;
    return arr[Front];
  }

  int back()
  {
    if(empty()) return -1;
    return arr[Back-1];
  }

  int size() { return Back-Front; }

  int pop()
  {
    if(empty()) return -1;
    int temp=arr[Front];
    arr[Front++]=0;
    return temp;
  }

  void push(int input)
  {
    if(Back+1==capacity) return;
    arr[Back++]=input;
  }

  ~Queue() { delete[] arr; }
};

int main(void)
{
  int n;
  cin>>n;
  Queue q=Queue(n);
  for(int i=0 ; i<n ; i++)
  {
    string str;
    cin>>str;
    if(str=="size")
      cout<<q.size()<<endl;
    else if(str=="pop")
      cout<<q.pop()<<endl;
    else if(str=="empty")
      cout<<q.empty()<<endl;
    else if(str=="front")
      cout<<q.front()<<endl;
    else if(str=="back")
      cout<<q.back()<<endl;
    else if(str=="push")
    {
      int temp;
      cin>>temp;
      q.push(temp);
    }
    else
      cout<<"ERROR"<<endl;
  }
  return 0;
}
