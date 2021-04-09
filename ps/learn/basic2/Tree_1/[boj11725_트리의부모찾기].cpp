#include <iostream>
#include <vector>
#include <queue>

int main(void) {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > gr(n+1);
  std::vector<bool> visit(n+1);
  std::vector<int> parent(n+1);
  for (int v1, v2, i = 1; i < n; i++) {
    visit[i] = false;
    parent[i] = -1;
    std::cin >> v1 >> v2;
    gr[v1].push_back(v2);
    gr[v2].push_back(v1);
  }
  visit[n] = false;
  parent[n] = -1;

  std::queue<int> q;
  q.push(1);
  visit[1] = true;
  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < (int)gr[node].size(); i++) {
      int child = gr[node][i];
      if (visit[child])
        continue;
      q.push(child);
      visit[child] = true;
      parent[child] = node;
    }
  }

  for (int i = 2; i <= n; i++) {
    printf("%d\n", parent[i]);
  }

  return 0;
}