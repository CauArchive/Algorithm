# idx, weight, value, v/w
def greedy_knapsack(table, max_capacity):
    # 쪼갤 수 있는 fractional knapsack 문제여서 benefit을 계산해야한다
    for item in table:
        item.append(item[2]/item[1])
    # 계산한 benefit을 기준으로 역순 정렬을 한다
    table = sorted(table, reverse=True, key=lambda item: item[3])
    # fraction된 아이템들 저장
    memo = []
    ans = 0
    left_capacity = max_capacity
    for i in range(len(table)):
        # 현재 테이블의 weight가 남아있는 배낭 무게를 넘어버리면
        if table[i][1] > left_capacity:
            # 물건을 fraction해서 넣는다
            frac = table[i][3] * left_capacity
            ans += frac
            # 물건을 담은 퍼센트를 포함해서 memo배열에 담는다
            memo.append((table[i][0], table[i][1],
                        table[i][2], frac/table[i][2]))
            break
        # 배낭무게를 넘지 않으면 상관없이 배낭에 담는다
        memo.append((table[i][0], table[i][1], table[i][2], 1))
        left_capacity -= table[i][1]
        ans += table[i][2]
        if left_capacity == 0:
            break
    print("<Solution>")
    print("Maximum Benefit for this items is : {0}".format(int(ans)))
    print("Associated Items List with fraction numbers : ")
    for item in memo:
        print(
            "{0}th : weight={1}, value={2}, percentage={3:.2f}".format(item[0], item[1], item[2], item[3]*100))


max_capacity = 16
# idx, weight, value
table = [[1, 6, 60], [2, 10, 20], [3, 3, 12],
         [4, 5, 80], [5, 1, 30], [6, 3, 60]]
greedy_knapsack(table, max_capacity)
