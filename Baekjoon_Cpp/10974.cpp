#include <iostream>
#include <cstring>
using namespace std;

void swap(int& a,int& b) {
  int temp=a;
  a=b;
  b=temp;
}

void Permutations(int* a, const int k,const int m) {
  if(k==m) {
    for(int i=0 ; i<=m ; i++) printf("%d ",a[i]);
    printf("\n");
  }
  else {
    for(int i=k ; i<=m ; i++) {
      swap(a[k],a[i]);
      Permutations(a,k+1,m);
      swap(a[k],a[i]);
    }
  }
}

int main(void) {
  int num;
  cin>>num;
  int* a=new int[num];
  for(int i=0 ; i<num ; i++)
    a[i]=i+1;
  Permutations(a,0,num-1);

}
