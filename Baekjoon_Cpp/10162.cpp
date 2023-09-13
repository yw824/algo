#include <iostream>
using namespace std;

int main(void)
{
  int arr[3]{0};
  int input;
  cin>>input;
  if(input%10)
  {
    cout<<-1;
    return 0;
  }

  arr[0]+=input/300;
  input=input%300;

  arr[1] += input/60 ;
  input = input%60;

  arr[2] += input / 10;

  cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
  return 0;
}
