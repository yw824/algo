"""

시골에 있는 태양이의 삼촌 댁에는 커다란 참외밭이 있다. 문득 태양이는 이 밭에서 자라는 참외가 도대체 몇 개나 되는지 궁금해졌다.
어떻게 알아낼 수 있는지 골똘히 생각하다가 드디어 좋은 아이디어가 떠올랐다.
유레카! 1m2의 넓이에 자라는 참외 개수를 헤아린 다음, 참외밭의 넓이를 구하면 비례식을 이용하여 참외의 총개수를 구할 수 있다.

1m2의 넓이에 자라는 참외의 개수는 헤아렸고, 이제 참외밭의 넓이만 구하면 된다. 참외밭은 ㄱ-자 모양이거나 ㄱ-자를 90도, 180도, 270도 회전한 모양(┏, ┗, ┛ 모양)의 육각형이다.
다행히도 밭의 경계(육각형의 변)는 모두 동서 방향이거나 남북 방향이었다.
밭의 한 모퉁이에서 출발하여 밭의 둘레를 돌면서 밭경계 길이를 모두 측정하였다.

예를 들어 참외밭이 위 그림과 같은 모양이라고 하자. 그림에서 오른쪽은 동쪽, 왼쪽은 서쪽, 아래쪽은 남쪽, 위쪽은 북쪽이다.
이 그림의 왼쪽위 꼭짓점에서 출발하여, 반시계방향으로 남쪽으로 30m, 동쪽으로 60m, 남쪽으로 20m, 동쪽으로 100m, 북쪽으로 50m, 서쪽으로 160m 이동하면 다시 출발점으로 되돌아가게 된다.

위 그림의 참외밭  면적은 6800m2이다. 만약 1m2의 넓이에 자라는 참외의 개수가 7이라면, 이 밭에서 자라는 참외의 개수는 47600으로 계산된다.

1m2의 넓이에 자라는 참외의 개수와, 참외밭을 이루는 육각형의 임의의 한 꼭짓점에서 출발하여 반시계방향으로 둘레를 돌면서 지나는 변의 방향과 길이가 순서대로 주어진다.
이 참외밭에서 자라는 참외의 수를 구하는 프로그램을 작성하시오.

"""

point: list
pole: list
melon: int
east: int
west: int
south: int
north: int

def _input():
    # TODO: 값 입력받기
    global pole, melon, point, east, west, south, north

    east, west, south, north = 1, 2, 3, 4

    melon = int(input())
    point = [[0, 0] for _ in range(6)]
    pole = [0, -3500, 3500, 3500, -3500] # east, west, south, north

    cur = [0, 0]
    order = 0
    while order < 6:
        direction, dist = map(int, input().split())

        if direction == east:  # 동쪽
            cur[0] += dist
            if cur[0] > pole[east]:
                pole[east] = cur[0]
        elif direction == west:  # 서쪽
            cur[0] -= dist
            if cur[0] < pole[west]:
                pole[west] = cur[0]
        elif direction == south:  # 남쪽
            cur[1] -= dist
            if cur[1] < pole[south]:
                pole[south] = cur[1]
        elif direction == north:  # 북쪽
            cur[1] += dist
            if cur[1] > pole[north]:
                pole[north] = cur[1]
        point[order][0] = cur[0]
        point[order][1] = cur[1]
        order += 1


def getCenterPoint():
    # 6개의 점을 모두 돌면서, 가운데 있는 점의 인덱스를 반환

    ans = -1
    for i in range(6):
        if point[i][0] == pole[west]:
            continue
        if point[i][0] == pole[east]:
            continue
        if point[i][1] == pole[south]:
            continue
        if point[i][1] == pole[north]:
            continue
        ans = i
        break

    return ans


def getSmallerSquareDist(index):
    # 가운데 점으로부터 인접한 거리의 점이 바로 작은 사각형의 가로, 세로이다. 이 가로, 세로를 반환

    before = point[(index - 1 + 6) % 6]
    after = point[(index + 1) % 6]

    x: int
    y: int
    if point[index][0] == before[0]:
        x = point[index][1] - before[1]
    else:
        x = point[index][0] - before[0]

    if point[index][0] == after[0]:
        y = point[index][1] - after[1]
    else:
        y = point[index][0] - after[0]

    return abs(x), abs(y)


def main():
    _input()
    index = getCenterPoint()

    x, y = getSmallerSquareDist(index)

    width = (pole[east] - pole[west])
    height = (pole[north] - pole[south])

    area = width * height - x * y

    print(melon * area)

if __name__ == "__main__":
    main()
