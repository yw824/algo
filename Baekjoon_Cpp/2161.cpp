#include <iostream>
using namespace std;

int* queue;

int main(void)
{
  int n;
  cin>>n;

  queue=new int[n*2];
  int front=0;
  int rear=0;

  for(int i=0 ; i<n ; i++)
    queue[rear++]=i+1;

  while(front!=rear)
  {
    cout<<queue[front++]<<" ";
    int temp=queue[front++];
    queue[rear++]=temp;
  }
  delete[] queue;
}
