#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str;
  getline(cin,str);
  while(true)
  {
    if(str=="END")
      break;
    for(int i=str.length()-1 ; i>=0 ; i--)
      cout<<str[i];
    cout<<endl;
    getline(cin,str);
  }
}
