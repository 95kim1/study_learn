#include <iostream>
#include <queue>
#include <stack>

void hideSeek(int &n, int &k) {
  bool visit[100001];
  int time[100001];
  int path[100001];
  for (int i = 0; i < 100001; i++) {
    visit[i] = false;
    time[i] = 0;
  }
  
  std::queue<int> q;
  int x = n;
  q.push(x);
  visit[x] = true;
  path[x] = -1;
  while(!q.empty()) {
    x = q.front();
    q.pop();

    if (x == k)
      break;

    if (x>0 && !visit[x-1]) {
      q.push(x-1);
      visit[x-1] = true;
      time[x-1] = time[x]+1;
      path[x-1] = x;
    }
    if (x<100001 && !visit[x+1]) {
      q.push(x+1);
      visit[x+1] = true;
      time[x+1] = time[x]+1;
      path[x+1] = x;
    }
    if (x < 50001 && !visit[2*x]) {
      int temp = 2*x;
      q.push(temp);
      visit[temp] = true;
      time[temp] = time[x]+1;
      path[temp] = x;
    }
  }

  printf("%d\n", time[k]);
  
  std::stack<int> p;
  int i = k;
  p.push(i);
  while(path[i]!=-1) {
    i = path[i];
    p.push(i);
  }
  
  while(!p.empty()) {
    printf("%d ", p.top());
    p.pop();
  }
  printf("\n");
}

int main(void) {
  int n, k;
  std::cin >> n >> k;

  hideSeek(n,k);

  return 0;
}