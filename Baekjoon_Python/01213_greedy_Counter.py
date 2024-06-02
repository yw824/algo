"""
[01213] 팰린드롬 만들기
https://www.acmicpc.net/problem/1213

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데,
임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

첫째 줄에 임한수의 영어 이름이 있다.
알파벳 대문자로만 된 최대 50글자이다.

첫째 줄에 문제의 정답을 출력한다.
만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.
"""
from collections import Counter


def make_palindrome(name):
    char_count = Counter(name)
    odd_count = 0
    odd_char = ''

    for char, count in char_count.items():
        if count % 2 == 1:
            odd_count += 1
            odd_char = char

    if odd_count > 1:
        return "I'm Sorry Hansoo"

    result = ''
    for char, count in sorted(char_count.items()):
        result += char * (count // 2)

    return result + odd_char + result[::-1]


name = input().strip()
print(make_palindrome(name))
