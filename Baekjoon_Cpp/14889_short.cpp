#include <iostream>
using namespace std;
const int SIZE = 27;

// 64ms밖에 안걸린다 , 내 풀이는 176ms나 걸린다.

int N, rst=100000000;
int power[SIZE][SIZE];
int temp[SIZE/2], temp2[SIZE/2];
int check[SIZE];

int solve()
{
    int a = 0, b = 0;

    for(int i=1;i<=N;i++)
    {
        if(check[i])
            temp[a++] = i;
        else
            temp2[b++] = i;
    }

    a = 0; b = 0;
    for(int i=0;i<N/2;i++)
        for(int j=0;j<N/2;j++)
        {
            a+=power[temp[i]][temp[j]];
            b+=power[temp2[i]][temp2[j]];
        }

    return a-b;
}

void team(int num, int dep)
{
    if(dep==N/2)
    {
        int x = solve();

        if(x<0)
            x = -x;

        if(rst>x)
            rst = x;
    }

    for(int i=num;i<=N;i++)
        if(!check[i])
        {
            check[i] = 1;
            team(i+1,dep+1);
            check[i] = 0;
        }
}

int main()
{
    cin >> N;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> power[i][j];

    team(1, 0);

    cout << rst;

    return 0;
}
