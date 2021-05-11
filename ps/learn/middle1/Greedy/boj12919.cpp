#include <iostream>
#include <string>
using namespace std;

void reverse(string &T)
{
  string::iterator s = T.begin();
  string::iterator e = T.end();
  e--;
  while (s < e)
  {
    char c = *s;
    *s = *e;
    *e = c;
    s++;
    e--;
  }
}

bool dfs(string &S, string T)
{
  if (S.length() == T.length())
  {
    if (S == T)
      return true;
    return false;
  }

  bool ans = false;

  if (T.back() == 'A')
  {
    T.pop_back();
    ans = dfs(S, T);
    T.push_back('A');
  }

  if (ans)
    return true;

  if (T[0] == 'B')
  {
    reverse(T);
    T.pop_back();
    ans = dfs(S, T);
  }

  return ans;
}

int main(void)
{
  string S, T;
  cin >> S >> T;
  if (dfs(S, T))
    cout << "1\n";
  else
    cout << "0\n";
  return 0;
}