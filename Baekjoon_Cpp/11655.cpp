#include <iostream>
#include <string>
using namespace std;

//M 이하면 +13, N 이상이면 -13

int main(void)
{
  string str;
  getline(cin,str); // 입력까지 완료

  for(int i=0 ; i<str.length() ; i++)
  {
    if(str[i]==' ')
      continue;
    if(str[i]>=65 && str[i]<=90)
    {
      if(str[i]<=77)
        str[i]=char(str[i]+13);
      else
        str[i]=char(str[i]-13);
    }
    else if(str[i]>=97 && str[i]<=122)
    {
      if(str[i]<=109)
        str[i]=char(str[i]+13);
      else
        str[i]=char(str[i]-13);
    }
  }
  cout<<str<<endl;
}
