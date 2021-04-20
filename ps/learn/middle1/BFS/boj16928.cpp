#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> next) {
  int pos;
  queue<int> q; //이동한 칸 저장
  vector<int> dist(101, -1); //해당 칸까지 주사위 몇 번 굴려서 이동?

  pos = 1;
  q.push(pos);
  dist[pos] = 0;

  while(!q.empty()) {
    pos = q.front();
    while(next[pos]!=-1) {//뱀 또는 사다리
      dist[next[pos]] = dist[pos];
      pos = next[pos];
    }
    q.pop();

    if (pos == 100) break;

    for (int i = 1; i <= 6; ++i) {//i: 주사위 눈금
      if (pos+i > 100 || dist[pos+i] != -1)//100넘거나 이미 이동했으면 pass
        continue;
      dist[pos+i] = dist[pos]+1;
      q.push(pos+i);
    }
  }

  return dist[100];
}

int main(void) {
  int n, m;
  vector<int> next(101, -1);
  cin >> n >> m;
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    cin >> next[x];
  }
  for (int x, i = 0; i < m; ++i) {
    cin >> x;
    cin >> next[x];
  }

  cout << solution(next) << '\n';
    
  return 0;
}