#include <stdio.h>
int a[22] = {}; int s; int t = 0;

void f(int l, int n, int sum){
    if(l == n){
        if(sum == s){
            t++;
        }
    }
    else{
        f(l + 1, n, sum);
        f(l + 1, n, sum + a[l]);
    }
}

int main(){
    int n;
    scanf("%d %d",&n,&s);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    f(0,n,0);
    if(s == 0){
        printf("%d",t-1);
    }
    else{
        printf("%d",t);
    }
}
