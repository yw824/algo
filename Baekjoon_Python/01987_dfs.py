"""
[알파벳]
https://www.acmicpc.net/problem/1987

세로
R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고,
좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데,
새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.

즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

첫째 줄에 R, C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20)

둘째 줄부터
R개의 줄에 걸쳐서 보드에 적혀 있는
C개의 대문자 알파벳들이 빈칸 없이 주어진다.
"""
R: int  # 행
C: int  # 열
w: list
alpha: set
ans: int


def init():
    global R, C, w, alpha, w, ans
    w = []
    alpha = set()
    ans = 0

    R, C = map(int, input().split())
    s: str
    w.append([''] * (C + 2))
    for _ in range(R):
        s = ['']
        exp = input()
        exp = [char for char in exp]
        s.extend(exp)
        s.append('')
        w.append(s)
    w.append([''] * (C + 2))

    alpha.add('')  # 빈칸 추가


# 이전에 이미 있는지 판단하고, 호출할 때 추가한다.
def dfs(x, y):
    global alpha, ans
    # 상
    if w[x][y - 1] not in alpha:
        alpha.add(w[x][y - 1])
        dfs(x, y - 1)
        alpha.remove(w[x][y - 1])
    # 하
    if w[x][y + 1] not in alpha:
        alpha.add(w[x][y + 1])
        dfs(x, y + 1)
        alpha.remove(w[x][y + 1])
    # 좌
    if w[x - 1][y] not in alpha:
        alpha.add(w[x - 1][y])
        dfs(x - 1, y)
        alpha.remove(w[x - 1][y])
    # 우
    if w[x + 1][y] not in alpha:
        alpha.add(w[x + 1][y])
        dfs(x + 1, y)
        alpha.remove(w[x + 1][y])

    # 만약 아무것도 없다면
    if len(alpha) > ans:
        ans = len(alpha)

def main():
    global alpha
    init()
    alpha.add(w[1][1])
    dfs(1, 1)
    alpha.remove(w[1][1])
    print(ans - 1)  # 구분을 위한 ''는 제거


if __name__ == "__main__":
    main()
