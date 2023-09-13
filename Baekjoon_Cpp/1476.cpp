#include <iostream>
using namespace std;
class Year{
public:
  int arr[3]; //arr[0] : E , arr[1] : S, arr[2] : M
  int year;
  int min()
  {
    int mini=arr[0];
    int count=1;
    int index=0;
    for(int i=1 ; i<=2 ; i++)
    {
      if(arr[i]<mini)
      {
        mini=arr[i];
        index=i;
      }
      else if(arr[i]==mini)
        count++;
    }
    if(count==3) return -1; // 세 정수가 모두 같으면 -1 반환
    return index; //가장 작은 수의 원소 인덱스 반환
  }

  void setE()
  {
    year+=arr[0];
    arr[1]-=arr[0];
    arr[2]-=arr[0];
    arr[0]=15;
  }

  void setS()
  {
    year+=arr[1];
    arr[0]-=arr[1];
    arr[2]-=arr[1];
    arr[1]=28;
  }

  void setM()
  {
    year+=arr[2];
    arr[0]-=arr[2];
    arr[1]-=arr[2];
    arr[2]=19;
  }

  void final()
  {
    year+=arr[0];
  }
};
int main(void) {
  Year jk; //준규
  cin>>jk.arr[0]>>jk.arr[1]>>jk.arr[2];
  jk.year=0;
  while (true) {
    int minIndex=jk.min();
    if(minIndex==-1)
    {
      jk.final();
      break;
    }
    switch(minIndex)
    {
      case 0 : jk.setE(); break;
      case 1 : jk.setS(); break;
      case 2 : jk.setM(); break;
    }
  }
  cout<<jk.year<<endl;
  return 0;
}


/* baekjoon 다른사람풀이

#include<stdio.h>

int main(){
    int e, s, m;
    scanf("%d %d %d",&e, &s, &m);
    int t = 1;
    if(e%15==0){
        e=0;
    }
    if(s%28==0){
        s=0;
    }
    if(m%19==0){
        m=0;
    }
    while(1){
        if(t%15 == e && t%28 == s && t%19 == m){
            break;
        }
        t++;
    }
    printf("%d",t);
    return 0;
}*/
