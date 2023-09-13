#include <iostream>
using namespace std;

int main(void)
{
  int m,n;
  cin>>m>>n;
  char chess[2][8][8], input[m][n]; // 첫번째 행렬이 "w"시작, 두번째 행렬이 "b"시작
  int wcount=64, bcount=64; // 8*8
  for(int i=0 ; i<m ; i++)
    for(int j=0 ; j<n ; j++)
    {
      if(m<8 && n<8){
        if((i+j)%2==0)
        {
          chess[0][i][j]='W';
          chess[1][i][j]='B';
        }
        else
        {
          chess[0][i][j]='B';
          chess[1][i][j]='W';
        }
      }
      cin>>input[i][j];
    }

  for(int i=m-8 ; i>=0 ; i--)
    for(int j=n-8 ; j>=0 ; j--)
    {
      int wtemp=0 , btemp=0;
      for(int k=0 ; k<8 ; k++)
        for(int l=0 ; l<8 ; l++)
        {
          if(chess[0][i+k][j+l]!=input[i+k][j+l]) wtemp++;
          if(chess[0][i+k][j+l]!=input[i+k][j+l]) btemp++;
        }
      cout<<wtemp<<" , "<<btemp<<endl;
      if(wtemp<wcount) wcount=wtemp;
      if(btemp<bcount) bcount=btemp;
    }
  wcount>bcount? cout<<bcount<<endl : cout<<wcount<<endl;
  return 0;
}
