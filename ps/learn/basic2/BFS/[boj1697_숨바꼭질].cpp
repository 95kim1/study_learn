#include <iostream>
#include <queue>

int hideSeek(int &n, int &k) {
  bool visit[100001];
  int time[100001];
  for (int i = 0; i < 100001; i++) {
    visit[i] = false;
    time[i] = 0;
  }
  
  std::queue<int> q;
  int x = n;
  q.push(x);
  visit[n] = true;
  while(!q.empty()) {
    x = q.front();
    q.pop();

    if (x == k)
      break;

    if (x>0 && !visit[x-1]) {
      q.push(x-1);
      visit[x-1] = true;
      time[x-1] = time[x]+1;
    }
    if (x<100001 && !visit[x+1]) {
      q.push(x+1);
      visit[x+1] = true;
      time[x+1] = time[x]+1;
    }
    if (x < 50001 && !visit[2*x]) {
      q.push(2*x);
      visit[2*x] = true;
      time[2*x] = time[x]+1;
    }
  }

  return time[k];
}

int main(void) {
  int n, k;
  std::cin >> n >> k;

  printf("%d\n", hideSeek(n,k));

  return 0;
}