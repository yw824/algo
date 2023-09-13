import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *

#파이썬은 map, filter와 같은 함수명 기능을 지원
# 다음과 같은 람다 표현식도 지원
list = list(map(lambda x: x + 10, [1, 2, 3]))
print(list)


# 다음은 홀수인 경우 2를 곱해 출력하라는 리스트 컴프리헨션이다.
a1 = [i * 2 for i in range(1, 10, 2)]

## 만약 리스트 컴프리헨션을 사용하지 않으면 다음과 같이 길게 풀어서 사용해야 한다.
a2 = []
for n in range(1, 10, 1):
    if n % 2 == 1:
        a2.append(n * 2)

print(a1, a2)

# 리스트 컴프리헨션만이라고 해서, 반드시 리스트만 가능한 것은 아니다.
# 다음과 같이 리스트 외에도 딕셔너리 등이 가능하도록 추가됐다.
# original이 선언되지 않아서 실행되지 않는 코드
a = {}
for key, value in original.items():
    a[key] = value

# 위의 코드는 다음과 같이 처리할 수 있다.
a = {key: value for key, value in original.items()}