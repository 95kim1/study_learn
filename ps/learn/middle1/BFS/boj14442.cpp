#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
using namespace std;

int solution(int k, vector<vector<int> > board) {
  int n = (int)board.size();
  int m = (int)board[0].size();
  int y, x, cnt;
  queue<tuple<int,int,int>> Q;
  vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, 0)));

  Q.push(make_tuple(0,0,0));
  dist[0][0][0] = 1;
  
  auto isOut = [n,m](int r, int c)->bool{
    if (0<=r&&r<n && 0<=c&&c<m)
      return false;
    return true;
  };

  while(!Q.empty()) {
    tie(y,x,cnt) = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int r = (i==3) ? y-1 : (i==1) ? y+1 : y;
      int c = (i==2) ? x-1 : (i==0) ? x+1 : x;

      if (isOut(r,c))
        continue;
      
      if (board[r][c] == 0 && dist[r][c][cnt] == 0) {
        dist[r][c][cnt] = dist[y][x][cnt] + 1;
        Q.push(tie(r,c,cnt));
      }
      else if (cnt < k && board[r][c] == 1 && dist[r][c][cnt+1] == 0) {
        dist[r][c][cnt+1] = dist[y][x][cnt] + 1;
        Q.push(make_tuple(r,c,cnt+1));
      }
    }
  }
  
  int answer = -1;
  for (int i = 0; i <= k; i++) {
    if (dist[n-1][m-1][i] > 0 && (answer == -1 || answer > dist[n-1][m-1][i]))
      answer = dist[n-1][m-1][i];
  }
  return answer;
}

int main(void) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> board(n, vector<int>(m));
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      board[i][j] = str[j]-'0';
    }
  }

  cout << solution(k, board) << '\n';

  return 0;
}