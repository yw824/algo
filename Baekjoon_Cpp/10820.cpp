#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str;
  getline(cin,str);
  int big=0,small=0,num=0,space=0;
  while(!str.empty())
  {
    for(int i=0 ; i<str.length() ; i++)
    {
      if(str[i]==' ')
        space++;
      else if(str[i]>=48 && str[i]<=57)
        num++;
      else if(str[i]>=65 && str[i]<=90)
        big++;
      else if(str[i]>=97 && str[i]<=122)
        small++;
    }
    cout<<small<<" "<<big<<" "<<num<<" "<<space<<"\n";
    small=0; big=0; num=0; space=0;
    getline(cin,str);
  }
}
