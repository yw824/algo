def solve():
    instr = ''
    instr = input()
    a, b, c = instr.split()
    a = int(a)
    b = int(b)
    c = int(c)

    lst = []

    lst.append(a)
    lst.append(b)
    lst.append(c)

    lst.sort()
    # print(lst)
    print(lst[0], lst[1], lst[2])


if __name__ == '__main__':
    solve()