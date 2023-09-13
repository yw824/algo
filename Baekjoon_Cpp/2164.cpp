#include <iostream>
#include <vector>
using namespace std;
//Queue 사용

class Queue
{
private:
  int* arr;
  int capacity;
  int front;
  int rear;
public:
  Queue(int input):capacity(2*input),front(0),rear(0) // front에 있는 원소가 가장 앞 원소
  {
    arr=new int[capacity];
    for(int i=1 ; i<=input ; i++)
      Push(i);
  }
  bool isEmpty() { return front==rear; }
  void Push(int input) { arr[rear++]=input; }
  int Pop()
  {
    if(isEmpty()) throw "Queue is Empty";
    return arr[front++];
  }
  void Execute()
  {
    while(front+1!=rear)
    {
      Pop();
      Push(Pop());
    }
    cout<<Pop()<<endl;
  }

};

int main(void)
{
  int num;
  cin>>num;
  Queue q=Queue(num);
  q.Execute();
  return 0;
}
