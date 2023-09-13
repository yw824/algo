#include <iostream>
#include <vector>
using namespace std;
//원형 이중연결 큐

class Queue
{
private:
  vector<int> queue; // 원소 벡터
  int* bag; // 값 저장 배열
  int current; // 현재 인덱스
  int order; // 인덱스 증가 횟수
  int top;// bag 최상위인덱스
public:
  Queue(int capacity,int amount):current(-1),order(amount),top(0)
  {
    bag=new int[capacity]{0};
    for(int i=1 ; i<=capacity ; i++)
      queue.push_back(i);
  }
  void Josephus()
  {
    while(queue.size())
    {
      current=(current+order)%queue.size();
      bag[top++]=queue[current];
      for(int i=current ; i<queue.size() ; i++)
        queue[i]=queue[i+1];
      queue.pop_back();
      current--;
      if(current==-1)
        current=queue.size()-1;
    }
    cout<<"<";
    for(int i=0 ; i<top ; i++)
    {
      cout<<bag[i];
      if(i!=top-1) cout<<", ";
      else cout<<">";
    }
  }

};

int main(void)
{
  int capacity,amount;
  cin>>capacity>>amount;
  Queue q=Queue(capacity,amount);

  q.Josephus();
}
