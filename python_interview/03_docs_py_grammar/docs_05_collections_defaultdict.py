import collections
# https://separang.tistory.com/106


# defaultdict를 사용했을 때
def defdictEx():  # 정상 작동하는 코드
    my_dict = collections.defaultdict(int)
    for w in 'mississippi':
        my_dict[w] += 1
    print(my_dict.items())


def notdefdictEx(): # 컴파일 에러 발생하는 코드
    my_dict = {}
    # defaultdict를 사용하지 않았을 때
    for w in 'mississippi':
        my_dict[w] += 1
    print(my_dict)


if __name__ == "__main__":
    defdictEx()
    # notdefdictEx() # 컴파일 에러
