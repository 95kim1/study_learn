#include <iostream>
#include <vector>
using namespace std;

int check_row[15] = {0,};//i번 row에 queen이 있으면 1
int check_col[15] = {0,};//i번 col에 queen이 있으면 1
int check_digLU[29] = {0,}; //왼쪽위에서 오른쪽 아래로 향하는 대각선, 오른쪽위 대각선부터 왼쪽아래 대각선에 0~28번호 부여, i번 대각선에 queen 있으면 1
int check_digRU[29] = {0,}; //위와 동일 단, 오른쪽위에서 왼쪽 아래로 향하는 대각선에 적용

bool checkQueen(int row, int col, int n) {
  if (check_row[row] || check_col[col] || check_digLU[row-col+n-1] || check_digRU[row+col])
    return true;
  return false;
}

int NQueen(int &n, int row) {
  if (row == n) {
    return 1;
  }

  int cnt = 0;
  for (int col = 0; col < n; col++) { // i: column, depth: row
    if (checkQueen(row, col, n)) continue;

    check_row[row] = check_col[col] = check_digLU[row-col+n-1] = check_digRU[row+col] = 1;

    cnt += NQueen(n, row+1);

    check_row[row] = check_col[col] = check_digLU[row-col+n-1] = check_digRU[row+col] = 0;
  }

  return cnt;
}

int main(void) {
  int n;
  cin >> n;

  printf("%d\n" ,NQueen(n, 0));

  return 0;
}