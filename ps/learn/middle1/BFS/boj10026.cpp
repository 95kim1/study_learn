#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

void bfs(int y, int x, vector<string>&board, int id, vector<vector<int>> &group, int which) {
  queue<tuple<int,int>> Q;
  int n = (int)board.size();
  int m = (int)board[0].length();

  Q.push(tie(y,x));
  group[y][x] = id;

  while(!Q.empty()) {
    tie(y,x) = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int Y = (i == 3) ? y-1 : (i==1) ? y+1 : y;
      int X = (i == 2) ? x-1 : (i==0) ? x+1 : x;
      if (!(0<=Y&&Y<n && 0<=X&&X<m))
        continue;
      if (group[Y][X] == 0 && board[y][x] == board[Y][X]) {
        group[Y][X] = id;
        Q.push(tie(Y,X));
      }
      if (which == 1 && group[Y][X] == 0 && (board[y][x] == 'G' || board[y][x] == 'R') && (board[Y][X] == 'G' || board[Y][X] == 'R')) {
        group[Y][X] = id;
        Q.push(tie(Y,X));
      }
    }
  }
}

tuple<int,int> solution(vector<string> &board) {
  int idnormal = 0, idspecial = 0;
  int n = (int)board.size();
  int m = (int)board[0].length();
  vector<vector<int>> normal(n, vector<int>(m,0));
  vector<vector<int>> special(n, vector<int>(m,0));

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (normal[y][x] == 0) {
        bfs(y, x, board, ++idnormal, normal, 0);
      }
      if (special[y][x] == 0) {
        bfs(y, x, board, ++idspecial, special, 1);
      }
    }
  }

  return tie(idnormal, idspecial);
}

int main(void) {
  int n;
  cin >> n;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }
  int y, x;
  tie(y,x) = solution(board);
  printf("%d %d\n", y, x);
  return 0;
}