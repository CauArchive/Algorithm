#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int dp[100];

void generate_matrix(int row, int column, vector<vector<int>> &my_matrix) {
  for (int i = 0; i < row; i++) {
    my_matrix.push_back(vector<int>(column, 0));
    for (int j = 0; j < column; j++) {
      my_matrix[i][j] = rand() % 100 + 1;
    }
  }
}

void print_matrix(vector<vector<int>> &input_matrix) {
  int row = input_matrix.size();
  int column = input_matrix[0].size();
  cout << "output of matrix " << row << " by " << column << "\n";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      cout << input_matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void matrix_chain_order(vector<int> dim) {
  int n = dim.size() - 1;
  vector<vector<float>> m(n + 1, vector<float>(n + 1, 0));
  vector<vector<float>> s(n + 1, vector<float>(n + 1, 0));

  for (int l = 2; l < n + 1; l++) {
    for (int i = 1; i < n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = numeric_limits<float>::infinity();
      for (int k = i; k < j; k++) {
        float q = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}

vector<vector<int>> matrix_multi(vector<vector<int>> &f_matrix,
                                 vector<vector<int>> &s_matrix) {
  print_matrix(f_matrix);
  print_matrix(s_matrix);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  vector<vector<int>> matrix_5x3;
  vector<vector<int>> matrix_3x7;
  vector<vector<int>> matrix_7x10;
  generate_matrix(5, 3, matrix_5x3);
  generate_matrix(3, 7, matrix_3x7);
  generate_matrix(7, 10, matrix_7x10);

  matrix_multi(matrix_5x3, matrix_3x7);

  return 0;
}