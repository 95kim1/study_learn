#include <iostream>
#include <vector>
#include <string>
using namespace std;

void calculate(vector<vector<int>> &matrix, int i, int j) {
  for (int r = i; r < i+3; r++) {
    for (int c = j; c < j+3; c++) {
      matrix[r][c] = 1 - matrix[r][c];
    }
  }
}

int solution(vector<vector<int>> &A, vector<vector<int>> &B) {
  int answer = 0;
  int n = (int)A.size();
  int m = (int)A[0].size();
  vector<vector<int>> matrix(n,vector<int>(m,0));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] != B[i][j])
        matrix[i][j] = 1;
    }
  }
  
  for (int i = 0; i+3 <= n; i++) {
    for (int j = 0; j+3 <= m; j++) {
      if (matrix[i][j] == 1) {
        calculate(matrix, i, j);
        answer += 1;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 1)
        return -1;
    }
  }

  return answer;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  string s;
  vector<vector<int>> A(n,vector<int>(m)), B;
  B = A;

  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      A[i][j] = s[j]-'0';
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      B[i][j] = s[j]-'0';
    }
  }

  cout << solution(A,B) << '\n';
  
  return 0;
}