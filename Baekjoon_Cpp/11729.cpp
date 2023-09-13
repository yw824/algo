#include <iostream>
using namespace std;
void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1)
        printf("%d %d\n", start, to);
    else
    {
        hanoi(n-1,start,bypass,to);
        printf("%d %d\n",start,to);
        hanoi(n-1,bypass,to,start);
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1<<num) -1 << "\n";
    hanoi(num,1,3,2);
}

// 만약 해당 문제에서 pow(2,num)을 사용하였다면, double형을 활용하는 pow의 특성상
// 입력 최대값인 20이 입력되면 오차범위가 커져 틀렸습니다. 라는 메세지가 출력된다.
