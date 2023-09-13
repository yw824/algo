#include <iostream>
using namespace std;

class Queue
{
public:
  int* arr;
  int capacity;
  Queue(int input):capacity(input) { arr=new int[input]{0}; }

};

int main(void)
{
  int n,m;
  cin>>n>>m;
  Queue q=Queue(n);

  return 0;
}
