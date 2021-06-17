#include <iostream>
#include <vector>
using namespace std;

void pairSum(vector<int> &integers, int given) {
  int sum = 0;
  for (int i = 0; i < integers.size() - 1; i++) {
    for (int j = i + 1; j < integers.size(); j++) {
      sum = integers[i] + integers[j];
      if (sum == given) {
        cout << "'" << integers[i] << "+" << integers[j] << "',";
      }
    }
  }
}

int main(void) {
  vector<int> arr(10, 0);
  for (int i = 0; i < arr.size(); i++) cin >> arr[i];
  int N;
  cin >> N;
  cout << "Output is : ";
  pairSum(arr, N);
  return 0;
}

// 2 4 3 5 6 -2 4 7 8 9