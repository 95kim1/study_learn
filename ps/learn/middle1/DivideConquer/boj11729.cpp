#include <iostream>
#include <vector>
#include <string>
using namespace std;

string makeStr(char s, char e)
{
  string ans = "";
  ans += s;
  ans += ' ';
  ans += e;
  ans += '\n';
  return ans;
}

void hanoi(int n, char s, char m, char e, string &log, int &k)
{
  if (n == 1)
  {
    log += makeStr(s, e);
    k++;
    return;
  }
  hanoi(n - 1, s, e, m, log, k);
  log += makeStr(s, e);
  k++;
  hanoi(n - 1, m, s, e, log, k);
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string log = "";
  int k = 0;
  hanoi(n, '1', '2', '3', log, k);
  cout << k << '\n'
       << log;

  return 0;
}