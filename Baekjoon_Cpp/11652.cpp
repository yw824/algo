#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
  map<long long,int> m;
  int order;
  cin>>order;
  for(int i=0 ; i<order ; i++)
  {
    long long num;
    cin>>num; // num 에 해당하는 key 있으면 value 1+, 없으면 1로 새로 생성
    if(m.find(num)!=m.end())
      m.find(num)->second++;
    else
      m.insert(make_pair(num,1));
  }
  long long maxindex=0;
  int max=0;
  for(map<long long,int>::iterator it=m.begin(); it!=m.end() ; ++it)
    if(it->second > max)
    {
      maxindex=it->first;
      max=it->second;
    }
  cout<<maxindex;
}

/*
int main(void)
{
  map<int,int> m;
  m.insert(make_pair(1,1));
  m.insert(make_pair(2,10));
  m.insert(make_pair(3,100));
  m.insert(make_pair(4,1000));
  //m.insert(make_pair(5,0));

  if(m.find(1)->second) m.find(1)->second++;
  if(m.find(2)->second) m.find(2)->second++;
  if(m.find(3)->second) m.find(3)->second++;
  if(m.find(4)->second) m.find(4)->second++;
  if(m.find(5)->second) m.find(5)->second++;

  cout<<m.find(1)->second<<endl;
  cout<<m.find(2)->second<<endl;
  cout<<m.find(3)->second<<endl;
  cout<<m.find(4)->second<<endl;
  cout<<m.find(5)->second<<endl;
}
*/
