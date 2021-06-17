#include <iostream>
#include <vector>
using namespace std;

void print_image(vector<vector<int>> &image) {
  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {
      cout.width(3);
      cout << image[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(void) {
  srand(time(NULL));
  vector<vector<int>> image(5, vector<int>(5, 0));
  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {
      image[i][j] = rand() % 100;
    }
  }
  cout << "original image matrix :\n";
  print_image(image);

  vector<vector<int>> rotated_image(5, vector<int>(5, 0));
  for (int i = 0; i < rotated_image.size(); i++) {
    for (int j = 0; j < rotated_image[i].size(); j++) {
      rotated_image[i][j] = image[image.size() - 1 - j][i];
    }
  }
  cout << "rotated image matrix :\n";
  print_image(rotated_image);

  return 0;
}