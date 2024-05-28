"""
[네트워크 연결]
https://www.acmicpc.net/problem/1922

각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라

첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다.
이 비용의 정보는 세 개의 정수로 주어지는데,
만약에 a b c 가 주어져 있다고 하면
a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다.

a와 b는 같을 수도 있다. ## 생략
"""
import sys

n: int  # 컴퓨터의 수
m: int  # 연결할 수 있는 선의 수
computers: list  # 선택한 여부
lines: list  # 간선
ans: int  # 최소 비용
# 간선의 개수가 정점의 개수가 될 때까지 이어야 한다. 그렇지 않으면 틀린 것으로 채점됨
cnt: int


def init():
    global n, m, computers, lines, ans, cnt
    n = int(input())
    m = int(input())
    ans = 0
    cnt = 0

    computers = [i for i in range(n + 1)]  # 맨 처음에는 본인 나타내고 있음
    lines = []
    # 비용, 지점, 도착점 순으로 넣기
    for _ in range(m):
        a, b, weight = map(int, sys.stdin.readline().split())
        if a == b:  # a, b는 같을 경우 굳이 연결할 필요 없음
            continue
        lines.append([weight, a, b])
    lines = sorted(lines, key=lambda x: x[0])

    # print(lines)  # 간선 가중치 기준으로 정렬되어 있어야 함


def find(v1: int):
    if computers[v1] == v1:
        return v1

    return find(computers[v1])


def union(v1: int, v2: int):
    global computers
    p1 = find(v1)
    p2 = find(v2)

    if p1 < p2:
        computers[p2] = p1
        return
    computers[p1] = p2


def kruskal():
    global lines, ans, cnt
    while len(lines):
        weight, a, b = lines.pop(0)

        # 이미 같은 그래프 내에 속해 있다면
        if find(a) == find(b):
            continue

        ans += weight
        union(a, b)
        cnt += 1
        print(a, b, weight)
        if cnt == n:
            break


def main():
    init()
    kruskal()
    print(ans)


if __name__ == "__main__":
    main()

"""
https://beyond-common-sense.tistory.com/14
[코멘트]
기본 Kruskal 알고리즘에 코드 몇 줄을 추가하여, union-by-rank를 구현하였다.

별게 아니라, union시에 분리집합의 깊이(rank)를 비교하여 rank를 최소화해주는 작업이다.

코드 몇 줄만 입력하면 되는 작업인데, 이걸 해줌으로써 시간복잡도가 최악의 상황으로 가는걸 방지해준다.

어떻게 알았냐하면, [백준 1717번 집합의 표현] 에서 그냥 Union했다가 시간초과가 난 적이 있었다
"""