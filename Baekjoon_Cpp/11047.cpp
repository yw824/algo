#include <iostream>
using namespace std;

int main(void)
{
  int input, aim;
  cin>>input>>aim;
  int* type=new int[input];
  int result=0;
  for(int i=input-1 ; i>=0 ; i--)
    cin>>type[i];
  for(int i=0 ; i<input ; i++)
  {
    result+=aim/type[i];
    aim=aim%type[i];
  }
  cout<<result<<endl;
  delete[] type;
  return 0;
}
