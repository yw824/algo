#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int order;
    cin >> order;
    while (order--) {

        // pair 로 선언
        int n;
        pair<int, int> p[100001];

        // pair 배열을 미리 만들어 놓고 그 값을 받기
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first >> p[i].second;
        }
        // 알고리즘 모듈 사용하여 첫번째 값을 기준으로 정렬
        sort(p, p + n);

        // 그리디 알고리즘

        // 오름차순으로 정렬된 값 중에서
        // 면접성적(second값)까지 낮게 된다면 합격자가 될 수 없으므로 패스
        // 면접성적이 앞의 지원자들보다 좋다면 합격이고, 그 성적이 면접성적의 합격 기준이 되며 반복
        int ans = 1;
        int temp = p[0].second;
        for (int i = 1; i < n; ++i) {
            if (p[i].second < temp) {
                ans++;
                temp = p[i].second;

                if (temp == 1) {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
