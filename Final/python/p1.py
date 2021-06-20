import sys


first = "ABCBDAB"
second = "BDCABA"
print("input is :", first, second)
# dp로 사용해줄 2차원 matrix를 선언한다
# dp계산을 쉽게 하기 위해 앞에 공백문자를 넣어준다
first = ' '+first
second = ' '+second
dp = [[0] * len(second) for i in range(len(first))]

# dp의 길이를 구하는 solution함수


def solution(f, s):
    for i in range(1, len(f)):
        for j in range(1, len(s)):
            if f[i] == s[j]:
                # 같은 문자열일 경우 dp배열의 대각에서 값을 가져와서 1 더해준 값을 현재 dp배열에 넣어준다
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                # 다른 문자열일 경우 현재 dp배열의 위 또는 왼쪽 배열 값중 가장 큰 값을 현재 dp배열에 넣어준다
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])


def print_dp(f, s):
    for i in range(len(f)):
        for j in range(len(s)):
            print(dp[i][j], end='')
        print()

# dp배열의 값을 이용해서 lcs문자를 구하는 함수


def print_lcs():
    # lcs문자를 저장할 변수
    lcs = ''
    # 현재 남아있는 문자의 갯수(처음값은 lcs의 길이)
    remain = dp[-1][-1]
    i = len(first)-1
    j = len(second)-1
    # 남아있는 문자의 갯수가 0일때까지 반복
    while remain != 0:
        # 만약 값이 업데이트 된 element가 아니라면 i--
        if dp[i][j] == dp[i-1][j]:
            i -= 1
        # 만약 값이 업데이트 된 element가 아니라면 j--
        elif dp[i][j] == dp[i][j-1]:
            j -= 1
        # 만약 문자열이 같아서 element값이 업데이트 된 배열이라면 lcs변수에 append
        else:
            lcs = first[i]+lcs
            remain -= 1
            i -= 1
            j -= 1
    # 구한 문자열을 return
    return lcs


solution(first, second)
print("after algo, dp array is :")
print_dp(first, second)
print("length of lcs is : ", dp[-1][-1])
print("string of lcs is : ", print_lcs())


# ABCBDAB
# BDCABA
