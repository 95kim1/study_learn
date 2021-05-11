#include <iostream>
using namespace std;

int main(void)
{
  int n, m, k;
  cin >> n >> m >> k;

  while (n != 2 * m)
  {
    if (n > 2 * m)
    {
      n--;
    }
    else
    {
      m--;
    }
    k--;
  }

  k = (k < 0) ? 0 : k;
  cout << m - (k + 2) / 3 << '\n';
  return 0;
}