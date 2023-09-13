import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *

'''
문자열 배열을 받아 애너그램 단위로 그룹핑하라. 

Input1 = ["eat","tea","tan","ate","nat","bat"]
Output1 = [["bat"],["nat","tan"],["ate","eat","tea"]]
'''


class Solution:
    def __init__(self):
        self.strs: List[str] = []

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        pass

    def main(self, strs: List[str]) -> List[List[str]]:
        self.strs = strs
        self.strs.sort()


# ------------------- end of Solution -


if __name__ == '__main__':
    sol = Solution()

    Input1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    Output1 = [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

    print(sol.main(Input1))
    print(Output1)
