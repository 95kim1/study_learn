#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int setNumAtPos(int num, int idx, int n) {
  int pos = (idx==0) ? 1 : (idx==1) ? 10 : (idx==2) ? 100 : 1000;
  return num - (num%(pos*10)) + num%pos + n*pos;
}

int solution(int start, int end, vector<int> &prime) {
  if (start == end) return 0;
  
  int cnt = 0;
  vector<bool> visit(10000, false);
  queue<int> Q;

  Q.push(start);
  visit[start] = true;

  while(!Q.empty()) {
    int len = (int)Q.size();
    cnt += 1;
    while(len--) {
      int num = Q.front();
      Q.pop();

      for (int i = 0; i < 4; i++) {
        for (int n = 0; n < 10; n++) {
          if (i == 3 && n == 0)
            continue;

          int temp = num;
          num = setNumAtPos(num, i, n);
          if (num == end) {
            return cnt;
          }
          
          if (prime[num]==1 && visit[num]==false) {
            visit[num] = true;
            Q.push(num);
          }
          
          num = temp;
        }
      }
    }
  }

  return -1;
}

int main(void) {
  int t, start, end;
  cin >> t;

  vector<int> prime(10000, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < 10000; i++) {
    if (prime[i] == 0)
      continue;
    for (int j = i+i; j < 10000; j+=i)
      prime[j] = 0;
  }

  while(t--) {
    cin >> start >> end;
    int answer = solution(start, end, prime);
    if (answer == -1)
      printf("Impossible\n");
    else
      printf("%d\n",answer);
  }

  return 0;
}