#include <iostream>
using namespace std;

int findKTh(int N, int r, int c, int R, int C, int num)
{
  if (N == 0)
  {
    return num;
  }

  int size = 1 << (N - 1);
  for (int i = 0; i < (1 << N); i += size)
  {
    for (int j = 0; j < (1 << N); j += size)
    {
      if (r + i <= R && R < r + i + size && c + j <= C && C < c + j + size)
      {
        return findKTh(N - 1, r + i, c + j, R, C, num);
      }
      num += size * size;
    }
  }
  return -1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r, c;
  cin >> n >> r >> c;

  cout << findKTh(n, 0, 0, r, c, 0) << '\n';
  return 0;
}