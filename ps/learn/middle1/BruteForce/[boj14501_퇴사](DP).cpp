#include <iostream>
class WORK {
public:
  int N;
  int T[15];
  int P[15];
};

int dfs(WORK &W, int day, int pay) {
  if (day == W.N) {
    return pay;
  }
  if (day > W.N)
    return 0;

  int temp1, temp2;
  
  temp1 = dfs(W, day+W.T[day], pay+W.P[day]);
  temp2 = dfs(W, day+1, pay);
  if (temp1 < temp2)
    temp1 = temp2;
  
  return temp1;
}

int main(void) {
  WORK W;
  std::cin >> W.N;
  for (int i = 0; i < W.N; i++) {
    std::cin >> W.T[i] >> W.P[i];
  }
  printf("%d\n", dfs(W, 0, 0));
  return 0;
}
