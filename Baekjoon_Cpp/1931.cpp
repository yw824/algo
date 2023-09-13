#include <iostream>
using namespace std;

// 그리디 - 회의실배정

typedef struct conference
{
int start;
int end;
}con;

int n;
con* table;

void ShowData()
{
    for(int i=0 ; i<n ; i++)
      printf("table %d : ( %d -> %d )\n",i,table[i].start,table[i].end);
}

void MergeTwoArea(int left, int middle, int right)
{
  int lIdx=left, rIdx=middle+1 , sIdx=0;
  con* temp=new con[right-left+1];
  while(lIdx<=middle && rIdx<=right)
  {
    if(table[lIdx].end<table[rIdx].end)
      temp[sIdx++]=table[lIdx++];
    else if(table[lIdx].end == table[rIdx].end && table[lIdx].start < table[rIdx].start )
      temp[sIdx++]=table[lIdx++];
    else
      temp[sIdx++]=table[rIdx++];
  }
  while(lIdx<=middle)
    temp[sIdx++]=table[lIdx++];
  while(rIdx<=right)
    temp[sIdx++]=table[rIdx++];

  for(int i=left ; i<=right ; i++)
    table[i]=temp[i-left];
  delete temp;
}

void MergeSort(int left, int right)
{
  if( left < right )
  {
    int middle=( left + right )/2;

    MergeSort( left , middle );
    MergeSort( middle+1 , right );
    MergeTwoArea( left , middle , right );
  }
}

void Sol()
{
  int index = 0;
  int end = 0;
  for(int i=0 ; i<n ; i++)
    if( table[i].start >= end )
    {
      index++;
      end = table[i].end;
      //printf("table %d : ( %d -> %d )\n",i,table[i].start,table[i].end);
    }
  cout << index << "\n";
}

int main(void)
{
  cin >> n;
  table=new con[n];
  for(int i=0 ; i<n ; i++)
    cin >> table[i].start >> table[i].end;

  //ShowData();
  //cout<<"---------------\n";

  // 정렬 기준 : 가장 먼저 끝나는 순,
  // 같은 시간에 끝난다면 먼저 시작하는 순으로
  MergeSort(0,n-1);

  //ShowData();
  //cout<<"---------------\n";

  Sol();
  delete table;
}
