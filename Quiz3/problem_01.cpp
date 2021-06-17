#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  int N, k = 1;
  cin >> N;
  while (true) {
    if (pow(2, k) > N) break;
    k++;
  }
  cout << "answer is : " << k - 1;
  return 0;
}