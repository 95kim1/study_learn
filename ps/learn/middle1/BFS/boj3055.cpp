#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

void flood(int n, int m, vector<string> &board) {
  int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
  int i, j;
  queue<tuple<int,int>> waterPos;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (board[i][j] != '.')
        continue;
      for (int d = 0; d < 4; d++) {
        int r = i + dr[d];
        int c = j + dc[d];
        if (!(0<=r&&r<n && 0<=c&&c<m))
          continue;
        if (board[r][c] == '*') {
          waterPos.push(tie(i,j));
          break;
        }
      }
    }
  }
  while(!waterPos.empty()) {
    tie(i,j) = waterPos.front();
    waterPos.pop();
    board[i][j] = '*';
  }
}

int solution(tuple<int,int> dochi, vector<string> &board) {
  int n = (int)board.size();
  int m = (int)board[0].length();
  int y, x, minute = 0;
  int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
  queue<tuple<int,int>> Q;
  vector<vector<bool>> visit(n, vector<bool>(m, false));

  Q.push(dochi);

  while(!Q.empty()) {
    int len = (int)Q.size();
    
    flood(n,m,board);

    while(len--) {
      tie(y,x) = Q.front();
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int r = y + dr[i];
        int c = x + dc[i];
        if (!(0<=r&&r<n && 0<=c&&c<m) || board[r][c]=='*' || board[r][c]=='X' || visit[r][c])
          continue;
        if (board[r][c] == 'D')
          return minute+1;
        visit[r][c] = true;
        Q.push(tie(r,c));
      }
    }

    minute+=1;
  }
  return -1;
}

int main(void) {
  int n, m, y, x;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      if (board[i][j]=='S') {
        y = i; x = j;
        board[i][j] = '.';
      }
    }
  }
  int answer = solution(tie(y,x), board);
  if (answer == -1)
    cout << "KAKTUS\n";
  else
    cout << answer << '\n';
  return 0;
}