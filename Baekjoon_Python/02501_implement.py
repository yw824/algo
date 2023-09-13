def main():
    n, k = input().split()
    n = int(n)
    k = int(k)

    ans = 0
    count = 0
    for i in range(1, n + 1):
        if n % i != 0:
            continue
        count += 1
        if count == k:
            ans = i
            break

    print(ans)

# end of main

if __name__ == '__main__':
    main()
