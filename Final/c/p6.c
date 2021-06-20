#include <stdio.h>

int solution(char* f, char* s) {
  printf("%s %s\n", f, s);
  printf("%s %s\n", f, s);
  return 1;
}

int main(void) {
  char first[100] = {0};
  char second[100] = {0};

  scanf("%s", first);
  scanf("%s", second);

  solution(first, second);
  return 0;
}