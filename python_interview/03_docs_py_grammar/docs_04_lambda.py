import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *


def func(x):
    return x.split()[1], x.split()[0]


def main():
    s = ['2 A', '1 B', '4 C', '1 A']

    # sorted로 정렬한 결과는 다음과 같다.
    print(sorted(s))  # 내장 함수

    '''
    각 요소의 번호 순 정렬이 아닌 그 뒤의 문자 순 정렬을 원하며, 
    문자가 동일한 경우에만 그 앞 번호 순으로 정렬되는 형태
    이때 리스트의 각 요소를 풀어서 별도 처리를 해줘야 하는데, 
    이럴 때 람다 표현식을 사용할 수 있다. 
    쉽게 말해 람다는 간단한 함수를 쉽게 표현할 수 있다. 
    '''
    # 다음 두 문장은 결과가 같다.
    s.sort(key=func)
    s.sort(key=lambda x: (x.split()[1], x.split()[0]))
    # 두 개 이상의 값을 람다 함수로 리턴할 때는 소괄호로 묶어서 반환해야 한다.

    '''
    그러나 람다 함수는 
    코드가 길어지고 map이나 filter와 함께 섞어서 사용하기 시작하면 
    가독성이 나빠질 수 있으므로 주의가 필요하다. 
    '''


if __name__ == '__main__':
    main()
