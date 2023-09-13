import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *
import unittest

'''
로그를 재정렬하라. 기준은 다음과 같다.
1. 로그의 가장 앞 부분은 식별자다.
2. 문자로 구성된 로그가 숫자 로그보다 앞에 온다.
3. 식별자는 순서에 영향을 끼치지 않지만, 문자가 동일할 경우 식별자 순으로 한다. 
4. 숫자 로그는 입력 순서대로 한다. 

입력1 : logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
출력1 : ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

입력2 : logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
출력2 : ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
'''

# 식별자는 의미 없다. 식별자 다음 원소들은 무조건 문자로만 이루어져있거나 숫자로만 이루어져 있다.
# 숫자끼리 모이고, 문자끼리 모였다면, 그제서야 식별자를 보고 식별자의 문자 순으로 구별한다.


def func(x):
    return x.split()[1], x.split()[0]


def lambdaEx(letters):
    for i in letters:
        print(func(i))


# 작성용.
def main(logs: List[str]) -> List[str]:
    letters, digits = [], []
    for log in logs:
        if log.split()[1].isalpha():  # 분리해서, 두 번째 요소가 문자이면
            letters.append(log)
            continue
        # 두 번째 요소가 숫자이면
        digits.append(log)

    # 2개의 키를 람다 표현식으로 정렬
    # https://kingofbackend.tistory.com/98

    # 정렬에 필요한 함수 실습 :
    # lambdaEx(letters)
    '''
    실행 결과 :
    (alp, let1)
    (own, let2)
    (art, let3)
    이때 왼쪽이 split()[1], 오른쪽이 split()[0]
    그래서 먼저 리턴한 쪽부터 먼저 정렬( 내용을 먼저 정렬 )
    두 번째 이후 내용으로 나중에 정렬( 키를 나중에 정렬 )
    '''

    # letters.sort(key=func)
    letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
    return letters + digits


# 제출용
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        for log in logs:
            if log.split()[1].isalpha():  # 분리해서, 두 번째 요소가 문자이면
                letters.append(log)
                continue
            # 두 번째 요소가 숫자이면
            digits.append(log)

        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        return letters + digits


if __name__ == '__main__':
    in1 = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    out1 = ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

    in2 = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    out2 = ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

    sol = Solution()

    '''
    print(main(in1))
    print(out1)
    print(main(in2))
    print(out2)
    '''

    print(sol.reorderLogFiles(in1))
    print(out1)
    
    print(sol.reorderLogFiles(in2))
    print(out2)
