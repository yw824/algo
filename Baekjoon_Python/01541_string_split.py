"""
[잃어버린 괄호]
https://www.acmicpc.net/problem/1541

세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.

그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다.
수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

55-50+40 > -35
10+20+30+40 > 100
00009-00009 > 0
"""
import sys
import re


tokens: list


def tokenize(exp: str):
    global tokens
    tokens = re.findall('\d+|-|\+', exp)


def is_digit(exp: str):
    try:
        int(exp)
        return True
    except ValueError:
        return False


def getMinResult() -> int:
    # is_digit("44") -> true

    ans = 0
    plus = 0
    minus = 0

    isMinus = False

    for token in tokens:
        if is_digit(token):
            val = int(token)
            if isMinus:
                minus += val
                continue
            plus += val
            continue
        if token == '+':
            continue
        # token is minus
        ans -= minus
        minus = 0
        ans += plus
        plus = 0
        isMinus = True
    else:
        ans -= minus
        ans += plus

    return ans


if __name__ == "__main__":
    s = sys.stdin.readline().rstrip()
    tokenize(s)
    print(getMinResult())


# 간결한 풀이
"""
먼저 - 단위로 나눈다. 그러면 맨 앞은 +일 것이고, 
-가 처음 시작된 것부터 그 다음 -가 시작될 때까지 괄호를 치면 된다. () - (,,,+,,,+,,,+,,,) - (,,,+,,,+,,,,) - ,,,,
그 다음에, 내부의 +로 뭉친 것들을 +와 숫자로 분리하기 위해 +로 split한다. 

```
formula = input().split('-')
sum = 0

for i in formula[0].split('+'):
  sum += int(i)

for i in formula[1:]:
  for j in i.split('+'):
    sum -= int(j)

print(sum)
```
"""

