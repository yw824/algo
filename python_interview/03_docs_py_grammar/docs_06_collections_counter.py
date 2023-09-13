import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *

def func():
    paragraph = "a, a, a, a, b,b,b,c, c"
    banned = ["a"]
    ans = "b"

    words = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower.split() if word not in banned]
    counts = collections.defaultdict(int)
    for word in words:
        counts[word] += 1

    '''
    여기서 개수를 담아두는 변수는 딕셔너리를 사용하여 defaultdict()을 아용해 int 기본값이 자동으로 부여되게 했다. 
    따라서 여기서는 키 존재 유무를 확인할 필요 없이 즉시 counts[word] += 1을 수행 가능 
    '''

    # return max(counts, key = counts.get)
    '''
    딕셔너리 변수인 counts에서 값이 가장 큰 키를 가져온다. 
    즉 수학에서 argmax와 동일하다. 
    그런데 파이썬의 기본 타입은 argmax를 지원하지 않는다. 
    과학 계산 라이브러리인 numpy는 이를 잘 지원하지만, 코딩테스트에서는 어떤 외부 라이브러리도 사용할 수 없다. 
    따라서 이처럼 max() 함수에 key를 지정해 argmax를 간접적으로 추출할 수 있다. 
    개수를 처리하는 부분은 Counter 모듈을 사용하면 조금 더 깔끔하게 처리할 수 있다. 
    '''

    counts = collections.Counter(words)
    return counts.most_common(1)[0][0]

    '''
    리턴값의 코드는 words에서 가장 흔하게 등장하는 단어의 첫 번째 값을 most_common(1)으로 추출한다. 
    문제의 입력값에서는 ball, 2가 되며, 이 값의 [0], [0]을 추출하여 최종적으로 첫 번째 인덱스의 키를 추출하게 한다. 
    이렇게 추출한 키인 ball은 가장 흔한 단어가 되므로, 이제 이 값을 리턴한다. 
    '''


if __name__ == '__main__':
    func()


