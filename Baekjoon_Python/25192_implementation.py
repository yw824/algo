"""
[인사성 밝은 곰곰이]
https://www.acmicpc.net/problem/25192

알고리즘 입문방 오픈 채팅방에서는 새로운 분들이 입장을 할 때마다 곰곰티콘을 사용해 인사를 한다.
이를 본 문자열 킬러 임스는 채팅방의 기록을 수집해 그 중 곰곰티콘이 사용된 횟수를 구해 보기로 했다.

ENTER는 새로운 사람이 채팅방에 입장했음을 나타낸다. 그 외는 채팅을 입력한 유저의 닉네임을 나타낸다.
닉네임은 숫자 또는 영문 대소문자로 구성되어 있다.

새로운 사람이 입장한 이후 처음 채팅을 입력하는 사람은 반드시 곰곰티콘으로 인사를 한다.
그 외의 기록은 곰곰티콘을 쓰지 않은 평범한 채팅 기록이다.

채팅 기록 중 곰곰티콘이 사용된 횟수를 구해보자!

첫 번째 줄에는 채팅방의 기록 수를 나타내는 정수
N 이 주어진다. (
1 <= N <= 100_000

두 번째 줄부터
N 개의 줄에 걸쳐 새로운 사람의 입장을 나타내는 ENTER, 혹은 채팅을 입력한 유저의 닉네임이 문자열로 주어진다.
1 <= 문자열 길이 <= 20

첫 번째 주어지는 문자열은 무조건 ENTER이다.

[input]
7
ENTER
pjshwa
chansol
chogahui05
ENTER
pjshwa
chansol

[output]
> 5
첫번째 새로운 사람이 들어온 뒤  pjshwa, chansol, chogahui05은 모두 곰곰티콘으로 인사했다.
두번째 새로운 사람이 들어온 뒤  pjshwa와 chansol은 다시 곰곰티콘으로 인사했다.
"""

# list로 단순히 구현하면 시간 초과 발생
# python set을 사용해야 한다.

# 맞춘 후 짧은 데이터
import sys
def short_solution():  # 80ms
    N = int(input())
    ans = 0
    chat_dic = {}
    for _ in range(N):
        chat = sys.stdin.readline().rstrip()
        if chat == "ENTER":
            ans += sum(chat_dic.values())
            chat_dic = {}
        else:
            chat_dic[chat] = 1
    ans += sum(chat_dic.values())

    print(ans)


if __name__ == "__main__":  # 3996ms
    inputs = int(input())

    members = set()
    ans = 0
    while inputs:
        inputs -= 1

        name = input()
        if name == 'ENTER':
            ans += len(members)
            members = set()
            continue
        if name in members:
            continue
        members.add(name)

    # 마지막까지 입력받고, members에 남아있는 멤버 추가하기
    ans += len(members)

    print(ans)
