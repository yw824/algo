## 문자열 슬라이싱
- 파이썬은 문자열 슬라이싱이라는 매우 편리한 기능을 제공한다. 
- 무엇보다 내부적으로 매우 빠르게 작동한다 
- 위치를 지정하면 해당 위치의 배열 포인터를 얻게 되며
- 이를 통해 연결된 객체를 찾아 실제 값을 찾아내는데, 이 과정은 매우 빠르게 진행되므로
- 문자열을 조작할 때는 항상 슬라이싱을 우선으로 사용하는 편이 속도 개선에 유리하다. 

## 특정 문자열 제거
```commandline
str="Hello, World, Python"

new_str = str.replace(',', '')
print(new_str)
```

## 한 줄 입력받기
- jupyter에서는 위의 ```sys.stdin.readline```이 제대로 작동하지 않아  
  무조건 input으로 받아야 한다. 
- 1개의 정수 입력받기
```commandline
  import sys
  a = int(sys.stdin.readline().rstrip())
```
- 여러 개의 정수 입력받기
```commandline
  import sys
  a, b, c  = map(int, sys.stdin.readline().rstrip().split())
```
- 여러 개의 정수 입력받아 리스트에 저장하기
```
  import sys
  data  = list(map(int, sys.stdin.readline().rstrip().split()))
  # [1, 2, 3]
```
- 공백 기준으로 분리된 여러 정수를 n번 입력 받아, 2차원 리스트에 저장하기
```commandline
  import sys
  n = int(sys.stdin.readline().rstrip())
  data = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]
  # [[1, 2, 3], [4, 5, 6]]
```

## 파이썬 정규식
- https://ponyozzang.tistory.com/335
- re : 정규식 처리를 위한 라이브러리
- ```re.sub（정규 표현식, 치환 문자, 대상 문자열）```
```commandline
import re
words=[word for word in re.sub(r'[^\w]', ' ', paragraph)]  # 정규식 표현
```
- \w : 단어 문자를 뜻한다.
- ^ : not을 의미
- 위 정규식은 단어 문자가 아닌 모든 문자를 공백으로 치환하는 역할을 한다. 

