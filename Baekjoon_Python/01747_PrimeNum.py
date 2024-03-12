"""
https://www.acmicpc.net/problem/1747

어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다.
예를 들어 79,197과 324,423 등이 팰린드롬 수이다.

어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고,
소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.
31
>> 101
"""
import math

def isPrime(x): # 소수인지 판별해주는 함수
    for i in range(2, int(math.sqrt(x)+1)):
        if x % i == 0:
            return False
    return True

N = int(input())
result = 0

for i in range(N, 1000001): # 입력값 N 부터 최대값 까지 순환
    if i == 1: # 1은 소수가 아니기 때문에 예외처리
        continue
    if str(i) == str(i)[::-1]: # 팰림드롬 수 일 경우
        if isPrime(i) == True: # 소수 판별 함수 적용
            result = i
            break

if result == 0: # 입력값이 만약 최대 값 100만일 경우
    result = 1003001 # 100만 이상이면서 팰림드롬 및 소수일 경우를 적용

print(result)