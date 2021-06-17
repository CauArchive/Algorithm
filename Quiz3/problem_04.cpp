#include <iostream>
#include <vector>
using namespace std;

int bst_search(vector<int> &input, int num) {
  int start = 0;
  int end = input.size() - 1;
  int mid;

  while (end - start >= 0) {
    mid = (start + end) / 2;
    if (input[mid] == num) {
      return mid;
    } else if (input[mid] > num) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

int main(void) {
  int N;
  cout << "enter num you want to find : ";
  cin >> N;
  cout << "enter list of integers : ";
  vector<int> integers(9, 0);
  for (int i = 0; i < 9; i++) cin >> integers[i];
  int idx = bst_search(integers, N);
  if (idx == -1)
    cout << "\nthat number is not exist\n";
  else
    cout << "that number exist at idx : " << idx;
  return 0;
}

// 12 34 37 45 57 82 99 120 134