#include <iostream>
#include <vector>
using namespace std;

class List
{
private:
  vector<int> v;
  int current;
public:
  void Set(int input)
  {
    for(int i=0 ; i<input ; i++)
    {
      cin>>current;
      v.push_back(current);
    }
  }
  bool isEmpty()
  {
    for(int i=0 ; i<v.size() ; i++)
      if(v[i]!=0) return false;
    return true;
  }
  void Initiate()
  {
    current=0;
    while(true)
    {
      int num=v[current];
      cout<<current+1<<" ";
      v[current]=0;
      if(isEmpty()) break;
      else if(num>0)
        for(int i=0 ; i<num ; i++)
        {
          current=(current+1)%v.size();
          if(v[current]==0) i--;
        }
      else if(num<0)
        for(int i=num ; i<=-1 ; i++)
        {
          current=(current-1+v.size())%v.size();
          if(v[current]==0) i--;
        }
    }
  }
  void ShowData()
  {
    for(int i=0 ; i<v.size() ; i++)
      cout<<v[i]<<" ";
    cout<<endl<<"-----------------ShowData-----------------"<<endl;
  }


};

int main(void)
{
  int num;
  cin>>num;
  List l=List();
  l.Set(num);
  l.Initiate();
}
