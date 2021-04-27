#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <tuple>
using namespace std;
using umap = unordered_map<int, string>;

// long long 때문에 헤맸다. num*num이 최대 10^18이 나오는데, int를 쓰면 표현을 못함.

string bfs(int s, int end) {
  queue<tuple<int,string>> Q;
  Q.push(tie(s,""));
  umap um;
  um[s] = "";
  long long num, next;
  string ops;

  while(!Q.empty()) {
    tie(num,ops) = Q.front();
    Q.pop();

    if (num == end) {
      return ops;
    }

    next = num*num;
    if (next <=end && um.find(next) == um.end()) {
      um[next] = um[num]+"*";
      Q.push(make_tuple(next, um[next]));
    }

    next = num+num;
    if (next <= end && um.find(next) == um.end()) {
      um[next] = um[num]+"+";
      Q.push(make_tuple(next, um[next]));
    }

    if (um.find(1) == um.end()) {
      um[1] = "/";
      Q.push(make_tuple(1, "/"));
    }
  }
  return "-1";
}

string solution(int start, int end) {
  if (start == end)
    return "0";

  return bfs(start, end); 
}

int main(void) {
  int s, e;
  cin >> s >> e;
  cout << solution(s,e) << '\n';
  return 0;
}