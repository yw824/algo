#include <iostream>

int n , r ;

// 1 ~ 9 : 9개 * 1 = 9
// 10 ~ 99 = 90개 * 2 = 180
// 100 ~ 999 = 900개 * 3
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i *= 10)
		r += n - i + 1;
    printf("%d", r);
    return 0;
}
