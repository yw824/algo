#include <iostream>
using namespace std;

class Stack
{
private:
  int* stack;
  int top;
  int len;
public:
  Stack(int input):top(-1),len(input) { stack=new int[len];  }
  bool isEmpty() { return top==-1; }
  void push(int input)
  {
    if(isEmpty()) stack[++top]=input;
    else if(input>stack[top]) stack[++top]=input;
  }
  int getElement() const { return top+1; }
  ~Stack() { delete[] stack; }
};


int main(void)
{
  int order;
  cin>>order;
  int num[order];
  Stack S=Stack(order);
  for(int i=0 ; i<order ; i++)
    cin>>num[i];
  for(int j=order-1 ; j>=0 ; j--)
    S.push(num[j]);
  cout<<S.getElement()<<endl;
  S.~Stack();
}
