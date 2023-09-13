#include <iostream>
using namespace std;

class spot
{
public:
  int x;
  int y;
};

spot* cor;
int n;

void MergeTwoArea(int left, int middle, int right)
{
  spot* temp=new spot[right-left+1];
  int rIdx=middle+1; int sIdx=0; int lIdx=left;

  while(rIdx<=right && lIdx <=middle)
  {
    if( cor[lIdx].y<cor[rIdx].y || (cor[lIdx].y==cor[rIdx].y && cor[lIdx].x<cor[rIdx].x) )
      temp[sIdx++]=cor[lIdx++];
    else
      temp[sIdx++]=cor[rIdx++];
  }
  while(lIdx<=middle)
    temp[sIdx++]=cor[lIdx++];
  while(rIdx<=right)
    temp[sIdx++]=cor[rIdx++];

  for(int i=left ; i<=right ; i++)
    cor[i]=temp[i-left];
  delete[] temp;
}

void MergeSort(int left, int right)
{
  int middle;
  if(left<right)
  {
    int middle=(left+right)/2;
    MergeSort(left,middle);
    MergeSort(middle+1,right);
    MergeTwoArea(left,middle,right);
  }
}

int main(void)
{
  cin>>n;
  cor=new spot[n];
  for(int i=0 ; i<n ; i++)
    cin>>cor[i].x>>cor[i].y;

  MergeSort(0,n-1);

  for(int i=0 ; i<n ; i++)
    cout<<cor[i].x<<" "<<cor[i].y<<"\n";

  delete[] cor;
}
