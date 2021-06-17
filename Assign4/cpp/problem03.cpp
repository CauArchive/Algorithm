#include <iostream>

using namespace std;

int dp[100];

int recur_fibo(int idx) {
  if (idx <= 2) return 1;
  if (dp[idx])
    return dp[idx];
  else {
    dp[idx] = recur_fibo(idx - 1) + recur_fibo(idx - 2);
    return dp[idx];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int input = 0;
  cin >> input;

  int result = recur_fibo(input);
  cout << result;

  return 0;
}