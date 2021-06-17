#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<string> vs;
  string input;
  for (int i = 0; i < 2; i++) {
    cin >> input;
    vs.push_back(input);
  }
  for (int i = 0; i < vs.size(); i++) {
    string cal = vs[i];
    bool isPanlindrome = true;
    for (int j = 0; j < cal.size() / 2; j++) {
      if (cal[j] != cal[cal.size() - j - 1]) {
        isPanlindrome = false;
        break;
      }
    }
    if (isPanlindrome == false)
      cout << cal << " is not Panlindrome\n";
    else
      cout << cal << " is Panlindrome\n";
  }
  return 0;
}