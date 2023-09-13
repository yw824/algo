#include <iostream>
#include <string>
using namespace std;
int main(void)
{
  string str;
  do {
    getline(cin,str);
  } while(!str.empty());
  cout<<"Hymn To Love";
}
