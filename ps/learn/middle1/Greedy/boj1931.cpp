#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
bool comp(tuple<int,int> a, tuple<int,int> b) {
  int sa,ea,sb,eb;
  tie(sa,ea) = a;
  tie(sb,eb) = b;
  if (ea < eb) return true;
  if (ea == eb && sa < sb) return true;
  return false;
}
int solution(vector<tuple<int,int>> meetings) {
  sort(meetings.begin(), meetings.end(), comp);
  int mye=-1, cnt=0, s, e;
  
  for (int i = 0; i < (int)meetings.size(); i++) {
    tie(s,e) = meetings[i];
    if (mye <= s) {
      mye = e;
      cnt++;
    }
  }
  return cnt;
}

int main(void) {
  int n, s, e;
  cin >> n;
  vector<tuple<int,int>> meetings;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    meetings.push_back(tie(s,e));
  }
  cout << solution(meetings) << '\n';
  return 0;
}