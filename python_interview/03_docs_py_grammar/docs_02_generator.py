# 제네레이터

# 임의의 조건으로 숫자 1억 개를 만들어내 계산하는 프로그램을 작성한다고 가정해 보자.
# 이 경우 제너레이터가 없다면 메모리 어딘가에 만들어낸 숫자 1억 개를 보관하고 있어야 한다.
# 그러나 제네레이터를 이용하면, 단순히 제네레이터만 생성해 두고, 필요할 때 언제든 숫자를 만들어낼 수 있다.
# 만약에 1억 개 중 100개 정도만 쓰인다면 차이는 더욱 클 것이다.

## yield

# 이때 yield 구문을 사용하면 제네레이터를 리턴할 수 있다.
# 기존의 함수는 return 구문을 맞닥뜨리면 값을 리턴하고도 모든 함수의 동작을 종료한다.
# 그러나 yield는 여기까지 실행 중이던 값을 내보낸다는 의미로,
# 중간값을 리턴한 다음 종료되지 않고 계속해서 맨 끝에 도달할 때까지 실행된다.

def get_natural_number():
    n = 0
    while n <= 10:
        n += 1
        yield n

# 이 경우 함수의 리턴 값은 다음과 같이 제네레이터가 된다.
# <generator object get_natural_number at 0x00000225FD7CAE40>

# 만약 다음 값을 생성하려면 next()로 추출하면 된다.
# 예를 들어 100개의 값을 생성하고 싶다면 다음과 같이 100번 동안 next()를 수행하면 된다.
g = get_natural_number()
for _ in range(1, 10):
    print(next(g))

# 아울러 제네레이터는 다음과 같이 여러 타입의 값을 하나의 함수에서 생성하는 것도 가능하다.
def generator():
    yield 1
    yield 'string'
    yield True

# >>> g = generator()
# >>> print(g)
# >>> next(g) # 1
# >>> next(g) # 'string'
# >>> next(g) # True