#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

long long solution(int n, int k, vector<pair<int,int>> &jewelries,  multiset<int> &backs) {//jewelry : M,V
  long long answer = 0;
  sort(jewelries.begin(), jewelries.end(), [](pair<int,int>&a, pair<int,int>&b)->bool {
    if (a.second < b.second)
      return true;
    return false;
  });

  while(!jewelries.empty() && !backs.empty()) {
    int M = jewelries.back().first;
    int V = jewelries.back().second;
    jewelries.pop_back();

    //backs[idx-1] < M <= backs[idx]
    multiset<int>::iterator it = backs.lower_bound(M);
    if (it != backs.end()) {
      backs.erase(it);
      answer += V;
    }
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> jewelries;
  multiset<int> backs;
  for (int m,v, i = 0; i < n; i++) {
    cin >> m >> v;
    jewelries.push_back(make_pair(m,v));
  }
  for (int temp, i = 0; i < k; i++) {
    cin >> temp;
    backs.insert(temp);	
  }
  cout << solution(n,k,jewelries,backs) << '\n';
  return 0;
}

