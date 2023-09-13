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

# 문자열을 뒤집는 함수를 작성
# 입력값은 문자 배열이며, 리턴 없이 리스트 내부를 직접 조작하라

# 예제 1 :
# Input: s = ["h","e","l","l","o"]
# Output: ["o","l","l","e","h"]

# 예제 2 :
# Input: s = ["H","a","n","n","a","h"]
# Output: ["h","a","n","n","a","H"]


# 코드 작성용
def main(s: List[str]) -> List[str]:
    ans: List[str] = s[::-1]
    return ans


# 제출용
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        # s = s[::-1]  이것도 되는 것이지만, LeetCode에서는 인정해주지 않는다. 플랫폼의 문제
        s[:] = s[::-1]  # 이렇게 풀어야 성공 처리해줌


if __name__ == "__main__":
    s1: List[str] = ["h","e","l","l","o"]
    s2: List[str] = ["H","a","n","n","a","h"]

    print(main(s1))
    print(["o","l","l","e","h"])

    print(main(s2))
    print(["h","a","n","n","a","H"])

    # 최종 제출 테스트용
    sol = Solution()
    sol.reverseString()


# TestCase를 작성
class CustomTests(unittest.TestCase):
    in1: List[str] = ["h","e","l","l","o"]
    out1: List[str] = ["o","l","l","e","h"]

    in2: List[str] = ["H","a","n","n","a","h"]
    out2: List[str] = ["h","a","n","n","a","H"]

    def test_run1(self):
        self.assertEqual(main(self.in1), self.out1)  # 하나라도 틀리면 다음 케이스는 수행 안됨

    def test_run2(self):
        self.assertEqual(main(self.in2), self.out2)

