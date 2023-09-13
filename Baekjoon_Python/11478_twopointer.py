instr: str = ''
ln: int = 0
ans: set = set()


def readdata():  # 데이터입력
    global instr
    global ln

    instr = input()
    ln = len(instr)


def twopointer():
    global instr
    global ln
    global ans

    temp: str

    for i in range(0, ln):
        for j in range(i, ln):
            temp = instr[i: j+1]
            if temp not in ans:
                ans.add(temp)


def solve():
    readdata()
    twopointer()

    global ans
    print(len(ans))


if __name__ == "__main__":
    solve()
