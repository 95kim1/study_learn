#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> coins, int price) {
  int answer = 0;
  while(price > 0) {
    if (coins.back() <= price) {
      answer += price / coins.back();
      price %= coins.back();
    }
    coins.pop_back();
  }
  return answer;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  cout << solution(coins, k) << '\n';
  return 0;
}