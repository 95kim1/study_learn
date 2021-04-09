#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::pair<int, int> bfs(std::vector<std::vector<std::pair<int,int> > > &gr, int &n, int node) {
  bool *visit = new bool[n+1];
  std::vector<int> dist(n+1);
  for (int i = 0; i <= n; i++) {
    visit[i] = false;
    dist[i] = 0;
  }
  int child, cost;
  int maxDepth = 0, maxChild;
  std::queue<int> q;
  q.push(node);
  visit[node] = true;
  while(!q.empty()) {
    node = q.front();
    q.pop();

    if (maxDepth < dist[node]) {
      maxDepth = dist[node];
      maxChild = node;
    }

    for (int i = 0; i < (int)gr[node].size(); i++) {
      child = gr[node][i].first;
      cost = gr[node][i].second;
      if (visit[child]) continue;
      visit[child] = true;
      q.push(child);
      dist[child] = dist[node]+cost;
    }
  }
  
  free(visit);
  return std::make_pair(maxDepth, maxChild);
}

int main(void) {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int> > > gr(n+1);
  std::vector<int> dist(n+1);
  for (int i = 0; i < n; i++) {
    int node;
    std::cin >> node;
    int child, cost;
    std::cin >> child;
    while(child != -1) {
      std::cin >> cost;
      gr[node].push_back(std::make_pair(child, cost));
      std::cin >> child;
    }
  }

  printf("%d\n", bfs(gr, n, bfs(gr, n, 1).second).first);

  return 0;
}