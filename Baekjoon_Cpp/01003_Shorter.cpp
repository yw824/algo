#include <iostream>
#define INF 1 << 20
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int dfs(int x)
{
    if (x < 2)
        return 0;
    int ret = INF;
    int a = dfs(x / 3) + x % 3 + 1;
    int b = dfs(x / 2) + x % 2 + 1;
    return min(a, b);
}

int main()
{
    int N;
    cin >> N;
    cout << dfs(N) << "\n";
}
