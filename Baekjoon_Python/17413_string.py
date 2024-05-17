"""
[단어 뒤집기 2]
https://www.acmicpc.net/problem/17413

문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.

먼저, 문자열 S는 아래와과 같은 규칙을 지킨다.

알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
문자열의 시작과 끝은 공백이 아니다.
'<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.
태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다.
단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다.
태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.
"""
import sys

# 해답 코드
def solution(chars):
    """
    한 글자씩 읽으면서, 답 페이지에 넣기
    경우 1 : <> 사이에 있는 거는 그대로 출력
    경우 2 : 꺾쇠 밖의 소문자/숫자일 때 : bucket에 모았다가 띄어쓰기 혹은 문자가 끝날 때까지 모은 다음에 뒤집어서 출력
    경우 3 : 꺾쇠 밖의 띄어쓰기 : 지금까지 모았던 것을 뒤집어서 출력한 후 띄어쓰기도 추가로 출력
    띄어쓰기가 꺾쇠 안에서 읽은 것인지, 밖에서 읽은 것인지 알기 위한 마스크 필요 : inBrace
    """
    bucket = ""
    answer = ""
    inBrace = False  # 꺾쇠 안에 있는 지 여부
    for char in chars:
        if char == '<':  # 이전에 bucket에 있는 char는 모두 뒤집어서 전달
            answer += bucket[::-1]
            bucket = "<"
            inBrace = True
            continue
        if char == '>':  # 이전에 bucket에 있는 것은 그대로 출력
            bucket += '>'
            answer += bucket
            bucket = ""
            inBrace = False
            continue
        if char == ' ':
            if inBrace:  # 꺾쇠 안에 있으면 그대로 넣기
                bucket += char

            else:  # 꺾쇠 안에 없으면 : 지금까지 모았던 글자를 모두 거꾸로 출력 후 띄어쓰기도 출력
                answer += bucket[::-1]
                answer += char
                bucket = ""
            continue
        # else : 그냥 숫자 혹은 소문자일 때
        bucket += char

    else:  # 남은 것이 있을 때 : >로 끝난 것이 아니므로, 남은 것들은 뒤집어서 전달
        answer += bucket[::-1]

    return answer


def main():
    chars = sys.stdin.readline().rstrip()  # 한 줄 전체 입력받기
    print(solution(chars))


def test():
    assert solution("baekjoon online judge") == "noojkeab enilno egduj"
    print("test 1/7 success")
    assert solution("<open>tag<close>") == "<open>gat<close>"
    print("test 2/7 success")
    assert solution("<ab cd>ef gh<ij kl>") == "<ab cd>fe hg<ij kl>"
    print("test 3/7 success")
    assert solution("one1 two2 three3 4fourr 5five 6six") == "1eno 2owt 3eerht rruof4 evif5 xis6"
    print("test 4/7 success")
    assert solution("<int><max>2147483647<long long><max>9223372036854775807") == "<int><max>7463847412<long long><max>7085774586302733229"
    print("test 5/7 success")
    assert solution("<problem>17413<is hardest>problem ever<end>") == "<problem>31471<is hardest>melborp reve<end>"
    print("test 6/7 success")
    assert solution("<   space   >space space space<    spa   c e>") == "<   space   >ecaps ecaps ecaps<    spa   c e>"
    print("test 7/7 success")
    print("test success")


if __name__ == "__main__":
    main()
    # test()
