#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str;
  cin >> str;

  int count = 0 ;
  for(int i=0 ; i<str.length() ; i++)
    if(i!=0 && str[i-1]!=str[i])
      count++;
  cout<<(count+1)/2;
}
 
