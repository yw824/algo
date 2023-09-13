#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end(),greater<>());
    if (s[s.length() - 1] != '0')
        cout << -1;
    else {
        long long sum = 0;
        for (auto o : s) { // 3의 배수는 다 더해도 3의 배수
            sum += o-'0'; // 다 더해도 3의 배수가 아니면 어떤 조합도 3의 배수가 아니다.
        }
        if (sum % 3 == 0)
            cout << s;
        else
            cout << -1;
    }
}
