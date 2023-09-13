#include<iostream>
#include<algorithm>
using namespace std;

int N ; 
int K ; // 총 무게 
int DP[101][100001];
int W[101];
int V[101];

// 점화식 max(DP[i-1][j], DP[i-1][j-W[i]])

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) // 현재 노드 ( 1 ~ N )
	{
		for (int j = 1; j <= K; j++) // 현재 무게( 1 ~ K )
		{
			 // 현재 무게를 더할 수 있으면 : 그래도 본인을 더하거나 더하지 않을 수 있다. 
			 if (j - W[i] >= 0) // 이전까지의 노드에서 무게 j까지의 최대 가치 vs 현재 무게 제외한 무게까지의 최대 가치 
			 	DP[i][j] = max( DP[i - 1][j] , DP[i - 1][j - W[i]] + V[i] ) ; 
			 else // 더하지 못하면 이전 것이 최대 - 그대로 
			 	DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K];

}