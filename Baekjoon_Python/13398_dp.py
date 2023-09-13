"""
10
10 -4 3 1 5 6 -35 12 21 -7
-> 35

10 -4 -3 9
-> 2개 생략되는 거 아닌지 확인

https://baby-ohgu.tistory.com/17
"""
n: int  # 입력되는 배열의 길이
arr: list  # 입력되는 배열
dp: list  # dp, 두 포인터 배열
ans: int  # 총합 값


def _input():
    global n, arr, dp, ans
    n = int(input())
    ans = -1001 * n
    arr = list(map(int, input().split()))

    dp = [[0] * n for _ in range(2)]
    dp[0][0] = arr[0]
    # 0번째 행 : 한 원소를 제거하지 않은 것
    # 1번째 행 : 한 원소를 제거한 것


"""
0번째 행 : 한 원소를 제거하지 않은 것 
    - 현재부터 다시 시작할 지 = arr[i]
    - 누적합 이어갈 지 = dp[0][i-1] + arr[i]
1번째 행 : 
    - 1. 이미 앞에서 한 번 제거되어 추가해야 할 때
    - 2. 앞에서 제거되지 않아 현재에서 제거할 때 
"""


def getans():
    global dp, ans
    for i in range(1, n):
        dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i])
        dp[1][i] = max(
            dp[1][i - 1] + arr[i],  # 이미 앞에서 한 번 제거되어 현재는 반드시 추가해야 할 때
            dp[0][i - 1]  # 앞에서 제거되지 않아 현재에서 제거할 때
        )

        ans = max(ans, dp[0][i], dp[1][i])


def print_():
    for i in dp:
        print(i)


def main():
    _input()
    if n == 1:  # N이 1인 경우는 반드시 선택을 해야하므로 dp[0][0] 출력
        print(arr[0])
        return

    getans()
    # print_()
    print(ans)


if __name__ == "__main__":
    main()
