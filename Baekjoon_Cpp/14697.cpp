#include <iostream>
using namespace std;

// 브루트포스 알고리즘 사용
class Node
{
public:
  int capacity; //입력된 수용인원
  int limit; // 한 방에만 들어갈 때 최대 몫
  int size; // 실제 경우 수
  Node() { capacity=0; limit=0; size=0; }
};

int main(void)
{
  int total=0; // 총 개수
  int student; // 학생 수
  Node room[3];
  cin>>room[0].capacity>>room[1].capacity>>room[2].capacity>>student;
  int count=0; // 경우의 수가 있으면 1, 없으면 0

  room[0].limit=student/room[0].capacity+1;
  room[1].limit=student/room[1].capacity+1;
  room[2].limit=student/room[2].capacity+1;
  room[0].size=0; room[1].size=0; room[2].size=0;

  for(room[0].size=0 ; room[0].size<room[0].limit ; room[0].size++)
  {
    for(room[1].size=0 ; room[1].size<room[1].limit ; room[1].size++)
    {
      for(room[2].size=0 ; room[2].size<room[2].limit ; room[2].size++)
      {
        total=(room[0].size*room[0].capacity)+(room[1].size*room[1].capacity)+(room[2].size*room[2].capacity);
        if(total==student)
        {
          count=1;
          goto EXIT;
        }
      }
    }
  }
EXIT:
  cout<<count<<endl;
}
