#include <iostream>
using namespace std;

int main(void)
{
  long long input;
  cin >> input;

  int n = 1;
  while( n++ )
  {
    if( (double) n * (n+1) / 2 > input)
      break;
  }
  cout<<n-1;
}
