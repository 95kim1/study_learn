#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, pair<int, int> start, pair<int, int> end) {
  pair<int, int> pos, nextPos; //이동한/할 칸 저장
  vector<vector<int> > dist(n, vector<int>(n, -1));// 해당 좌표로 몇 번 만에 이동?
  queue<pair<int, int> > q;
  int dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1, 1, -2, 2, -1, 1};

  pos = start;
  dist[pos.first][pos.second] = 0;
  q.push(pos);

  while(!q.empty()) {
    pos = q.front();
    q.pop();

    if (pos == end) 
      break;

    for (int d = 0; d < 6; ++d) {//d: direction idx
      nextPos = {pos.first+dx[d], pos.second+dy[d]};
      if (!(0<=nextPos.first && nextPos.first<n && 0<=nextPos.second && nextPos.second<n) || dist[nextPos.first][nextPos.second] != -1) 
        continue; //map 범위 벗어나거나, 이미 방문 했던 좌표는 pass
      dist[nextPos.first][nextPos.second] = dist[pos.first][pos.second]+1;
      q.push(nextPos);
    }
  }

  return dist[end.first][end.second];
}

int main(void) {
  int n;
  pair<int,int> start, end;
  cin >> n >> start.first >> start.second >> end.first >> end.second;
  cout << solution(n, start, end) << '\n';
  return 0;
}