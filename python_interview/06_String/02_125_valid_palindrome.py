import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *

# 대소문자 구분 X , 각 문자열이 팰린드롬인지 구분
# 영문자와 숫자만을 구분

# 입력 예시
# A man, a plan, a canal: Panama
# race a car

class Solution: # 인터뷰 답 풀이
    def isPalindrome(self, s: str) -> bool:
        strs = []
        for char in s:
            if char.isalnum():  # 영문자, 숫자 여부를 판별하는 함수
                strs.append(char.lower())  # 소문자로 변경하여 추가

        while len(strs) > 1:
            if strs.pop(0) != strs.pop():  # 맨 뒤의 것과 맨 앞의 것 빼기 - 홀수이면?
                return False

        # 리스트의 pop(0)은 O(n)이다. -> 최대 n번 : O(n^2)

        return True

    def main2(self, s: str) -> bool:  # 내 풀이, 맞는 풀이

        comp: str = ''  # 비교할 배열
        rv: str = ''  # 뒤집어진 배열
        ln: int = len(s)  # 문자열 길이
        # --- 사용할 자원 준비 ---

        s = s.lower()  # 소문자화
        alpha: str = 'abcdefghijklmnopqrstuvwxyz'

        for char in s:  # 알파벳만 뽑기
            if char in alpha:
                comp += char
        ln = len(comp)  # 알파벳만 뽑은 새로운 배열 길이 다시 재기

        rv = comp[::-1]  # 뒤집어진 배열 생성

        for i in range(ln):  # 비교
            if comp[i] != rv[i]:
                return False
        return True

    # deque 자료형을 이용한 최적화
    def isPalindrome_deque(self, s: str) -> bool:
        # 자료형 deque 선언
        strs: Deque = collections.deque()

        for char in s:
            if char.isalpha():  # 각 글자가 알파벳인지 확인
                strs.append(char.lower())

        while len(strs) > 1:  # 비교할 수가 2개 이상 남아있어야 비교, 하나 남았을 때는 길이가 홀수일 때
            if strs.popleft() != strs.pop():
                return False

        # deque의 popleft()는 O(1)이다. -> 최대 n번 : O(n)

        return True

    # 슬라이싱을 이용한 문제 문제 풀이
    def isPalindrome_slicing(self, s: str) -> bool:
        s = s.lower()

        # 정규식으로 불필요한 문자 필터링
        s = re.sub('[^a-z0-9]', '', s);

        return s == s[::-1]  # 슬라이싱




if __name__ == "__main__":
    sol = Solution()
    s_in = sys.stdin.readline()
    print(sol.isPalindrome(s_in))
    # print(sol.main2(s_in))

    # main1()
    # main2()


# ------------------------------- 내 풀이, 틀린 풀이 ----------------------------------
def main1():  # 내 풀이, 틀린 풀이
    string: str
    rv: str
    string = sys.stdin.readline()  # 한 줄 읽기
    string = string.lower()[:-1]  # 문자열 소문자로 낮추기 + 한 줄 읽기라서 엔터까지 들어가므로 크기 1 줄이기
    ln: int = len(string)  # 길이

    alpha: str = 'abcdefghijklmnopqrstuvwxyz'
    rv: str = [string[i] for i in range(ln - 1, -1, -1)] # 0까지니까 -1 이전까지

    mid: int = int((ln - 1)/2)
    ind: int # 거짓이 되는 인덱스
    status: bool = True

    for i in range(mid + 1): # mid까지
        print(i, string[i], rv[i])
        if rv[i] not in alpha and string[i] not in alpha:
            continue
        # 여기서 틀림 : 한 쪽은 스페이스바 , 한 쪽은 알파벳이면 틀리다고 나옴
        # 알파벳 아닌 것을 다 지운 소문자만 남겨 놓아야 함

        if rv[i] != string[i]:
            ind = i
            status = False
            break

    if status:
        print('true')
    else:
        print('false', ind, string[ind], rv[ind])
# --- end of main1