#include <iostream>
#include <vector>
#include <queue>
#define WALL 1
#define VIRUS 2
#define SAFE 0
using namespace std;


int bfs(vector<vector<int> > &lab, int r, int c) {
  pair<int, int> pos = {r,c};
  queue<pair<int,int> > q;
  int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}, R, C;
  int cnt = 0;

  q.push(pos);
  while(!q.empty()) {
    pos = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {//d:direction
      R = pos.first + dr[d];
      C = pos.second + dc[d];
      if (!(0<=R && R<(int)lab.size() && 0<=C && C<(int)lab[0].size()) || lab[R][C] != SAFE)//범위 넘어가거나 벽,바이러스 있는 칸은 바이러스 확산x
        continue;

      lab[R][C] = VIRUS;
      cnt++;
      q.push({R,C});
    }
  }

  return cnt;
}

int dfs(vector<vector<int> > &lab, int depth, int zeros, int r, int c) {
  if (depth == 0) { //벽 3개 선택 완료
    vector<vector<int> > labCopy;
    labCopy.assign(lab.begin(), lab.end());
    int addedVirus = 0; //새로 추가된 바이러스 개수
    for (int i = 0; i < (int)labCopy.size(); ++i) {
      for (int j = 0; j < (int)labCopy[0].size(); ++j) {
        if (labCopy[i][j] != VIRUS)
          continue;
        addedVirus += bfs(labCopy, i, j); //virus 확산 및 새로 추가된 바이러스 개수 더하기
      }
    }

    return zeros - addedVirus;
  }

  //벽 선택
  int cnt = 0, temp = 0;
  for (int j, i = r; i < (int)lab.size(); ++i) {
    j = (i==r)?c:0;
    for (; j < (int)lab[0].size(); ++j) {
      if (lab[i][j] != SAFE)
        continue;
      
      lab[i][j] = WALL;

      temp = dfs(lab, depth-1, zeros-1, i, j);    

      if (temp > cnt)
        cnt = temp;
      
      lab[i][j] = SAFE;
    }
  }
  return cnt;
}

int solution(vector<vector<int> > lab) {
  int zeros = 0; //벽이 아닌 안전지대 개수
  for (int i = 0; i < (int)lab.size(); i++) {
    for (int j = 0; j < (int)lab[0].size(); j++) {
      if (lab[i][j] == SAFE)
        zeros++;
    }
  }

  return dfs(lab, 3, zeros, 0, 0);
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > lab(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> lab[i][j];
    }
  }
  cout << solution(lab) << '\n';
  return 0;
}