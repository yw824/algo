# 리트코드 기본 라이브러리

다른 대부분의 코딩 테스트 사이트와 마찬가지로  
leetcode 또한 외부 라이브러리의 import 불가능 

그러나 언어 차원에서 기본으로 제공하는 라이브러리는 사용 가능  
그러나 IDE에서는 포함하여 사용하여야 한다. 

```commandline
import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *
```

모든 코드에서도 이 모듈들은 추가로 import 선언 X  
타입 선언도 이미 모든 타입이 처리되어 있으므로  
컬렉션의 여러 타입을 자유롭게 import 하지 않고 사용 가능

다음은 Deque를 collections 모듈을 이용해 타입과 함께 선언하는 예다. 
```commandline
d: Deque = colections.deque()
```

github.com/onlybooks/algorithm-interview  
https://bit.ly/algorithm-interview-youtube