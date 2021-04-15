#include <iostream>
class WORK {
public:
  int N;
  int T[15];
  int P[15];
  int DP[16];
};

int main(void) {
  WORK W;
  std::cin >> W.N;
  for (int i = 0; i < W.N; i++) {
    std::cin >> W.T[i] >> W.P[i];
    W.DP[i] = 0;
  }
  W.DP[W.N] = 0;
  
  for (int i = 0; i < W.N; i++) {
    for (int j = 0; j < i; j++)
      if (W.DP[i]<W.DP[j])
        W.DP[i] = W.DP[j];
        
    if (i+W.T[i]<=W.N && W.DP[i+W.T[i]] < W.DP[i] + W.P[i])
      W.DP[i+W.T[i]] = W.DP[i] + W.P[i];
  }
  for (int i = 0; i < W.N; i++)
    if (W.DP[W.N] < W.DP[i])
      W.DP[W.N] = W.DP[i];

  // for (int i =0; i< W.N;i++)
  //   printf("%d ", W.DP[i]);
  printf("%d\n", W.DP[W.N]);
  return 0;
}
