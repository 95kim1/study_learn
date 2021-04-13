#include <iostream>
#include <vector>

void init(int n, std::vector<int> &seq) {
  for (int temp, i = 0; i < n; i++) {
    std::cin >> temp;
    seq.push_back(temp);
  }
}

// seq: original sequence
// s: target sum
// idx: cur index of original sequence
// tempS: current sum of choosed numbers in original sequence
// cnt: the number of choosed numbers; default zero
int cntEqToS(std::vector<int> &seq, int s, int idx, int tempS, int cnt = 0) {
  if (idx == (int)seq.size()) {
    if (cnt && tempS == s) {
      return 1;
    }   
    return 0;
  }
  
  int count = 0;

  // seq[idx] 선택
  count += cntEqToS(seq, s, idx+1, tempS+seq[idx], cnt+1);
  
  // seq[idx] 선택 x
  count += cntEqToS(seq, s, idx+1, tempS, cnt);
  
  return count;
}

void solution() {
  int n, s;
  std::cin >> n >> s;
  std::vector<int> seq;
  
  init(n, seq);

  printf("%d\n", cntEqToS(seq, s, 0, 0));
}

int main(void) { 
  solution();
  return 0;
}