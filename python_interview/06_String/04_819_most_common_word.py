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
금지된 단어를 제외한 가장 흔하게 등장하는 단어를 출력하라.
대소문자 구분을 하지 않으며, 구두점(마침표, 심표) 또한 무시한다.

paragraph = "Bob hit a ball, the hit ball flew far after it was hit." 
banned = ['hit']
return = 'ball'

paragraph = "a, a, a, a, b,b,b,c, c"
banned = ["a"]
return = "b"

paragraph = 
"L, P! X! C; u! P? w! P. G, S? l? X? D. w? m? f? v, x? i. z; x' m! U' M! j? V; l. S! j? r, K. O? k? p? p, H! t! z' X! v. 
u; F, h; s? X? K. y, Y! L; q! y? j, o? D' y? F' Z; E? W; W' W! n! p' U. N; w? V' y! Q; J, o! T? g? o! N' M? X? w! V. w? o' 
k. W. y, k; o' m! r; i, n. k, w; U? S? t; O' g' z. V. N? z, W? j! m? W! h; t! V' T! Z? R' w, w? y? y; O' w; r? q. G, V. x? n, 
Y; Q. s? S. G. f, s! U? l. o! i. L; Z' X! u. y, Q. q; Q, D; V. m. q. s? Y, U; p? u! q? h? O. W' y? Z! x! r. E, R, r' X' V, b. z, 
x! Q; y, g' j; j. q; W; v' X! J' H? i' o? n, Y. X! x? h? u; T? l! o? z. K' z' s; L? p? V' r. L? Y; V! V' S. t? Z' T' Y. s? i? Y! G? r; 
Y; T! h! K; M. k. U; A! V? R? C' x! X. M; z' V! w. N. T? Y' w? n, Z, Z? Y' R; V' f; V' I; t? X? Z; l? R, Q! Z. R. R, O. S! w; p' T. u? U! 
n, V, M. p? Q, O? q' t. B, k. u. H' T; T? S; Y! S! i? q! K' z' S! v; L. x; q; W? m? y, Z! x. y. j? N' R' I? r?
 V! Z; s, O? s; V, I, e? U' w! T? T! u; U! e? w? z; t! C! z? U, p' p! r. x; U! Z; u! j; T! X! N' F? n! P' t, X. s; q'"
banned = ["m","i","s","w","y","d","q","l","a","p","n","t","u","b","o","e","f","g","c","x"]
return = "z"
'''


# 제출용
class Solution:
    def __init__(self):
        self.instr: str = ''  # 입력받은 문자열
        self.ln: int = 0  # 문자열 길이
        self.words: List[str] = []
        self.count: dict = dict()
        self.banned: List[str] = []

    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # 정규식 표현
        words = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower().split() if word not in banned]

        counts = collections.Counter(words)
        return counts.most_common(1)[0][0]



    def brute(self, paragraph: str, banned: List[str]) -> str:  # 내 풀이, 틀린 테스트 케이스를 보며 구두점을 일일이 수정하였다.
        self.instr = paragraph
        self.banned = banned
        self.banned.append('')

        self.instr = self.instr.replace("'", ' ')
        self.instr = self.instr.replace(';', ' ')
        self.instr = self.instr.replace('?', ' ')
        self.instr = self.instr.replace('.', ' ')
        self.instr = self.instr.replace('!', ' ')
        self.instr = self.instr.replace(' ', ',')  # 구두점 제거
        self.instr = self.instr.lower()  # 전체 소문자화

        self.words = self.instr.split(',')

        for item in self.words:
            if item in banned:
                continue
            if item not in self.count:
                self.count[item] = 1
                continue
            self.count[item] += 1

        ans_str: str = ''
        ans_val: int = 0

        for item in self.count.keys():
            if self.count[item] > ans_val:
                ans_str = item
                ans_val = self.count[item]

        return ans_str


if __name__ == "__main__":
    paragraph1: str = "Bob hit a ball, the hit ball flew far after it was hit."
    banned1: List[str] = ["hit"]
    ans1 = 'ball'

    sol = Solution()

    # print(sol.mostCommonWord(paragraph1, banned=banned1))
    # print(ans1)

    paragraph2 = "Bob. hIt, baLl"
    banned2 = ["bob", "hit"]
    ans2 = "ball"
    # print(sol.main2(paragraph=paragraph2, banned=banned2))

    print(sol.mostCommonWord(paragraph2, banned=banned2))
    print(ans2)


