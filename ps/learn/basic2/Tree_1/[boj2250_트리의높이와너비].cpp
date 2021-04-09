#include <iostream>
#include <stack>
#include <queue>
#include <utility>
int main(void) {
  int n;
  std::cin >> n;
  int **child = new int*[n+1];
  int *parent = new int[n+1];
  for (int i = 1; i <= n; i++) {
    child[i] = new int[2];
    parent[i] = -1;
  }
  
  int height = 0, width = n;

  for (int node, left, right, i = 1; i <= n; i++) {
    std::cin >> node >> left >> right;
    child[node][0] = left;
    child[node][1] = right;
    if (left != -1)
      parent[left] = node;
    if (right != -1)
      parent[right] = node;
  }

  //root 찾기
  int root = 1;
  while(parent[root]!=-1) {
    root = parent[root];
  }
  


  //in-order dfs로 각 노드마다 탐색하는 순서를 저장(ordres[노드] = 탐색 순서)
  bool *visit = new bool[n+1];
  int *orders = new int[n+1];
  for (int i = 0; i <= n; i++)
    visit[i] = false;
  std::stack<std::pair<int, int> > s;
  int node = root;
  int depth = 0;
  int order = 0;
  s.push(std::make_pair(depth, node));
  while(!s.empty()) {
    //현재 노드 방문
    depth = s.top().first;
    node = s.top().second;
    s.pop();

    //왼쪽 자식 방문 준비
    int childNode = child[node][0];
    if (childNode != -1 && !visit[childNode]) {
      s.push(std::make_pair(depth, node));
      s.push(std::make_pair(depth+1, childNode));
      continue;
    }
    
    //현재 노드 방문 완료
    if (!visit[node]) {
      visit[node] = true;
      orders[node] = order++;
    }

    //오른쪽 자식 방문 준비
    childNode = child[node][1];
    if (childNode != -1 && !visit[childNode]) {
      s.push(std::make_pair(depth, node));
      s.push(std::make_pair(depth+1, childNode));
    }
  }
  free(visit);


  
  int *minWidths = new int[n+1];
  int *maxWidths = new int[n+1];
  for (int i = 0; i <= n; i++) {
    minWidths[i] = n;
    maxWidths[i] = 0;
  }
  
  //bfs로 각 depth 마다 max, min index 찾기
  std::queue<std::pair<int, int> > q;
  q.push(std::make_pair(0, root));
  maxWidths[0] = minWidths[0] = orders[root];
  while(!q.empty()) {
    depth = q.front().first;
    node = q.front().second;
    q.pop();

    for (int i = 0; i < 2; i++) {
      int childNode = child[node][i];

      if (childNode == -1)
        continue; 
      
      q.push(std::make_pair(depth+1, childNode));
      
      if (maxWidths[depth+1] < orders[childNode])
        maxWidths[depth+1] = orders[childNode];
      
      if (minWidths[depth+1] > orders[childNode])
        minWidths[depth+1] = orders[childNode];
    }
  }

  //정답 구하기
  int h = 0, w = 0;
  for (int i = 0; i <= depth; i++) {
    if (maxWidths[i] - minWidths[i] + 1 > w) {
      w = maxWidths[i] - minWidths[i] + 1;
      h = i+1;
    }
  }

  printf("%d %d\n", h, w);

  free(minWidths);
  free(maxWidths);
  free(orders);
  for (int i = 0; i < n; i++) {
    free(child[i+1]);
  }
  
  
  return 0;
}