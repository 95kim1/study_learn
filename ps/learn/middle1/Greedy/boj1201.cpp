#include <iostream>
#include <stack>
using namespace std;

void pushStack(stack<int> &s, int top, int bot)
{
  for (int i = bot; i <= top; i++)
  {
    s.push(i);
  }
}

int main(void)
{
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1)
  {
    if (n == k)
    {
      for (int i = n; i > 0; i--)
        cout << i << " ";
      cout << '\n';
    }
    else
    {
      cout << "-1\n";
    }
    return 0;
  }

  int q = (n - k) / (m - 1);
  int r = (n - k) % (m - 1);
  if (!(1 <= q && q < k || (q == k && r == 0)))
  {
    cout << "-1\n";
    return 0;
  }

  stack<int> s;
  // n ~ n - (k-1)
  pushStack(s, n, n - k + 1);
  n -= k;

  while (r > 0)
  {
    pushStack(s, n, n - q);
    n -= q + 1;
    r--;
  }

  while (n > 0)
  {
    pushStack(s, n, n - q + 1);
    n -= q;
  }

  while (!s.empty())
  {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';

  return 0;
}