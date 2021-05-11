#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	string str;
  cin >> str;
  int a = 0;
  bool zero = false;
  for (char c : str) {
    if (c == '0') {
      zero = true;
      continue;
    }
    a += c - '0';
    a %= 3;
  }

  if (a == 0 && zero) {
    sort(str.begin(), str.end(), [](char a, char b)->bool{return a > b;});
    cout << str << '\n';
  }
  else
    cout << "-1\n";

	return 0;
}