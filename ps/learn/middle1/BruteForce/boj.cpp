#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MAP{
public:
  int n, m;
  vector<string> map;
  bool visit[256];
};

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0,1,0,-1};
int dfs(MAP &M, int depth, int r, int c) {
  M.visit[M.map[r][c]] = true;
  
  int length = 0;
  for (int d = 0; d < 4; d++) {
    int R = r + dr[d];
    int C = c + dc[d];
    if (!(0<=R && R<M.n && 0<=C && C<M.m) || M.visit[M.map[R][C]])
      continue;
    int temp = dfs(M, depth+1, R, C);
    if (temp > length)
      length = temp;
  }

  M.visit[M.map[r][c]] = false;

  if (length == 0)
    length = depth;

  return length;
}

int main(void) {
  MAP M;
  std::cin >> M.n >> M.m;
  M.map.resize(M.n);
  for (int i = 0; i < M.n; i++) {
    std::cin >> M.map[i];
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    M.visit[i] = false;
  }

  printf("%d\n", dfs(M, 1, 0, 0));

  return 0;
}