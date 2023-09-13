#include <iostream>
#include <algorithm>
using namespace std;
int a[100001][2];//0인 경우는 위에(오른쪽) //1인 경우는 밑에(왼쪽))
int d[100001][3];
//0은 해당 열에서 스티커 선택 X 1은 왼쪽 스티커 선택 2는 오른쪽 스티커 선택
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t,n,ans; //t는 tc, n는 배열 길이,  ans는 해답

	cin>>t;
	while(t--){
		cin>>n;
		for(int j=0;j<2;j++){
			for(int i=1;i<=n;i++){
				cin>>a[i][j]; //각 배열에 입력값 입력받기
			}
		}
		for(int i=1;i<=n;i++){
			d[i][0]=max({d[i-1][0],d[i-1][1],d[i-1][2]});
			d[i][1]=max(d[i-1][0],d[i-1][2])+a[i][1];
			d[i][2]=max(d[i-1][0],d[i-1][1])+a[i][0];
		}
		ans=max({d[n][0],d[n][1],d[n][2]});
		cout<<ans<<'\n';
	}


	return 0;
}
