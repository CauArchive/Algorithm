dp = [0 for i in range(11)]
dp_counter = 0
non_dp_counter = 0


def dp_recur_fibo(idx):
    global dp_counter
    dp_counter += 1
    if idx <= 2:
        return 1
    if dp[idx]:
        return dp[idx]
    else:
        dp[idx] = dp_recur_fibo(idx - 1) + dp_recur_fibo(idx - 2)
        return dp[idx]


def recur_fibo(idx):
    global non_dp_counter
    non_dp_counter += 1
    if idx <= 2:
        return 1
    else:
        return recur_fibo(idx-1) + recur_fibo(idx-2)


def reset():
    global dp
    global dp_counter
    global non_dp_counter
    dp = [0 for i in range(11)]
    dp_counter = 0
    non_dp_counter = 0


print(dp_recur_fibo(5))
print(dp_recur_fibo(10))
reset()

recur_fibo(5)
print("calculation count for idx 5 (non dp) : ", non_dp_counter)
dp_recur_fibo(5)
print("calculation count for idx 5 (dp) : ", dp_counter)
reset()

recur_fibo(10)
print("calculation count for idx 10 (non dp) : ", non_dp_counter)
dp_recur_fibo(10)
print("calculation count for idx 10 (dp) : ", dp_counter)
