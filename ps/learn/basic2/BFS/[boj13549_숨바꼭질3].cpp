#include <iostream>
#include <deque>

int hideSeek(int &n, int &k) {
  bool visit[100001];
  int time[100001];
  for (int i = 0; i < 100001; i++) {
    visit[i] = false;
    time[i] = -1;
  }
  std::deque<int> temp;
  std::deque<int> q;
  int x = n;
  q.push_back(x);
  visit[x] = true;
  time[x] = 0;
  while(!q.empty()) {
    x = q.front();
    q.pop_front();

    if (x == k)
      break;


    if (x < 50001 && !visit[2*x] && k - x > 2*x - k) {
      q.push_front(2*x);
      visit[2*x] = true;
      time[2*x] = time[x];
    }
    if (x>0 && !visit[x-1]) {
      q.push_back(x-1);
      visit[x-1] = true;
      time[x-1] = time[x]+1;
    }
    if (x<k && !visit[x+1]) {
      q.push_back(x+1);
      visit[x+1] = true;
      time[x+1] = time[x]+1;
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