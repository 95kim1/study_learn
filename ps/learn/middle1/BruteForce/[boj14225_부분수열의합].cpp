#include <iostream>
#include <vector>

void eraseNums(std::vector<int> &numbers, std::vector<int> &seq, int idx, int sum, int cnt = 0) {
  if (idx == (int)seq.size()) {
    if (cnt) { //erase
      numbers[sum] = 1;
    }
    return;
  }
  
  // 선택 seq[idx]
  eraseNums(numbers, seq, idx+1, sum+seq[idx], cnt+1);

  // 선택 seq[idx] x
  eraseNums(numbers, seq, idx+1, sum, cnt);
}

void printMin(std::vector<int> &numbers) {
  int i = 1;
  while(numbers[i]==1) {
    i++;
  }
  printf("%d\n", i);
}

void solution() {
  int n;
  std::cin >> n;
  std::vector<int> seq(n);
  for (int i = 0; i < n; i++) {
    std::cin >> seq[i];
  }
  std::vector<int> numbers(2000000, 0);
  eraseNums(numbers, seq, 0, 0);
  
  printMin(numbers);
}

int main(void) {
  solution();
  return 0;
}