#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  cin >> n;

  long long my;
  int* arr = new int[n-1];

  cin >> my;

  for(int i=0 ; i<n-1 ; i++)
    cin >> arr[i];

  sort(arr,arr+n-1);

  for(int i=0 ; i<n-1 ; i++)
  {
    if( my <= arr[i] )
    {
      cout << "No";
      return 0;
    }
    my += arr[i];
  }
  cout << "Yes";
  delete[] arr;
}
