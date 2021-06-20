#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[101][101];
char lcs[101];

void solution(char* f, char* s) {
  for (int i = 1; i < f[i]; i++) {
    for (int j = 1; j < s[j]; j++) {
      if (f[i] == s[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}

void get_lcs(int i, int j, char* str, int lcs_size) {
  lcs_size--;
  while (i >= 1 && j >= 1) {
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else if (dp[i][j] == dp[i][j - 1])
      j--;
    else {
      lcs[lcs_size--] = str[i];
      i--;
      j--;
    }
  }
}

void print_dp(int f_size, int s_size) {
  for (int i = 0; i <= f_size; i++) {
    for (int j = 0; j <= s_size; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  char first[101] = {0};
  char second[101] = {0};
  scanf("%s %s", first + 1, second + 1);
  int f_size = strlen(first + 1);
  int s_size = strlen(second + 1);
  solution(first, second);
  get_lcs(f_size, s_size, first, dp[f_size][s_size]);

  print_dp(f_size, s_size);
  printf("\nthe answer is %d, character is %s", dp[f_size][s_size], lcs);
  return 0;
}

/*
ABCBDAB
BDCABA
*/