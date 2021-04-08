#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <utility>

int escapeMazeBreakingWall(std::vector<std::string> map_, int n, int m) {
  int time[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      time[i][j] = -1;
    }
  }
  int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

  std::deque<std::pair<int, int> > q;
  int r = 0, c = 0;
  q.push_back(std::make_pair(r,c));
  time[r][c] = 0;
  
  while(!q.empty()) {
    r = q.front().first;
    c = q.front().second;
    q.pop_front();

    if (r == n-1 && c == m-1)
      break;
    
    for (int i = 0; i < 4; i++) {
      int R = r+dr[i];
      int C = c+dc[i];
      if (!(0<=R && R<n && 0<=C && C<m) || time[R][C]!=-1)
        continue;
      
      if (map_[R][C] == '0') {
        q.push_front(std::make_pair(R, C));
        time[R][C] = time[r][c];
      }
      else {
        q.push_back(std::make_pair(R, C));
        time[R][C] = time[r][c] + 1;
      }
    }
  }
  return time[n-1][m-1];
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> m >> n;
  std::vector<std::string> map_(n);
  for (int i = 0; i < n; i++) {
    std::cin >> map_[i];
  }
  printf("%d\n", escapeMazeBreakingWall(map_, n, m));
  return 0;
}