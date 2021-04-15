#include <iostream>
class WORK {
public:
  int N;
  int T[15];
  int P[15];
  int DP[15];
};

int dfs(WORK &W, int day, int pay) {
  if (day == W.N) {
    return pay;
  }
  if (day > W.N)
    return 0;

  if (W.DP[day] != -1)
    return W.DP[day];
  
  W.DP[day] = dfs(W, day+W.T[day], pay+W.P[day]);
  int temp = dfs(W, day+1, pay);
  if (W.DP[day] < temp)
    W.DP[day] = temp;
  
  return W.DP[day];
}

int main(void) {
  WORK W;
  std::cin >> W.N;
  for (int i = 0; i < W.N; i++) {
    std::cin >> W.T[i] >> W.P[i];
    W.DP[i] = -1;
  }
  
  printf("%d\n", dfs(W, 0, 0));
  return 0;
}
