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

int main(void)
{
  string S, T;
  cin >> S >> T;
  while (S.length() != T.length())
  {
    if (T.back() == 'A')
    {
      T.pop_back();
    }
    else
    {
      T.pop_back();
      reverse(T);
    }
  }
  if (S == T)
    cout << "1\n";
  else
    cout << "0\n";
  return 0;
}