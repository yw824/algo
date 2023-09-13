#include <iostream>
using namespace std;

float portion(int* arr, int index)
{
  float temp=0;
  int count=0;
  for(int i=0 ; i<index ; i++)
    temp+=arr[i];
  temp=temp/index;
  for(int i=0 ; i<index ; i++)
    if(arr[i]>temp)
      count++;
  return (float)count/index;
}

int main(void)
{
  int Case;
  cin>>Case;
  for(int i=0 ; i<Case ; i++)
  {
    int num;
    cin>>num;

    int* arr=new int[num];
    for(int j=0 ; j<num ; j++)
      cin>>arr[j];

    float result=100*portion(arr,num);
    printf("%.3f%%\n",result);
    delete[] arr;
  }
  return 0;
}
