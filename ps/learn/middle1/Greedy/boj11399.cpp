#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> p) {
  int answer = 0;
  int n = (int)p.size();
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    answer += p[i] * (n-i);
  }
  return answer;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  cout << solution(p) << '\n';
  return 0;
}