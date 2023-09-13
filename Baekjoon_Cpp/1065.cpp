#include <iostream>
using namespace std;



int main(void)
{
    int num;
    cin>>num;
    int count=99;
    if(num<=110)
    {
      if(num<99)
        cout<<num;
      else
        cout<<count;
      return 0;
    }
    for(int i=111 ; i<=num ; i++)
    {
      int term=(i/10)%10-(i%10);
      int temp=(i/100)-(i/10)%10;
      if(temp==term)
        count++;
    }
    cout<<count;
    return 0;
}
