#include <iostream>
using namespace std;

int main(void)
{
  int WarHP,WarATK,MonHP,MonATK,P,S;
  cin>>WarHP>>WarATK>>MonHP>>MonATK;
  cin>>P>>S;
  bool used=false;
  while(true)
  {
    MonHP-=WarATK;
    if(MonHP<=0)
    {
      cout<<"Victory!"<<endl;
      break;
    }
    WarHP-=MonATK;
    if(WarHP<=0)
    {
      cout<<"gg"<<endl;
      break;
    }
    cout<<WarHP<<","<<MonHP<<",";
    if(used==false && 1<=MonHP && MonHP<=P)
    {
      used=true;
      MonHP+=S;
    }
    cout<<MonHP<<","<<used<<endl;
  }
}
