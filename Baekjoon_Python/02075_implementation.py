"""
02075_priority_queue.py
https://www.acmicpc.net/problem/2075

N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데,
모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.

이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오.
표에 채워진 수는 모두 다르다.

첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다.
표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다

첫째 줄에 N번째 큰 수를 출력한다.
"""


def main():
    n = int(input())
    queue = []
    for i in range(n):
        lst = list(map(int, input().split()))
        queue.extend(lst) # 지금까지 받은 거를 합친 다음에
        queue.sort(reverse=True) # 큰 수로 정렬하고
        queue = queue[:n] # 앞에서부터 n개만 자른다.
    print(queue[n-1]) # 맨 마지막 것이 n번째 큰 수이다.


if __name__ == "__main__":
    main()

"""
다른 답지에는 우선순위큐 사용한다고 하는데, 
이 문제에서만 이 답이 되는 지는 모르겠다. 
입력받은 리스트를 지금의 큐와 통합하고, 큰 수부터 정렬한 후, 
큰 수부터 n개를 자르면, 그게 n번째로 큰 수가 되는 것 같다. 
"""