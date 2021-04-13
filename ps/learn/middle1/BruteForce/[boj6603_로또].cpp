#include <iostream>
#include <vector>

void printLottos(std::vector<int> &seq, int idx, int cnt, std::vector<int> &lotto) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++) {
      printf("%d ", lotto[i]);
    }
    printf("\n");
    return;
  }

  if (idx == (int)seq.size()) 
    return;

  //seq[idx] 선택
  lotto.push_back(seq[idx]);
  printLottos(seq, idx+1, cnt+1, lotto);
  lotto.pop_back();
  
  //seq[idx] 선택 x
  printLottos(seq, idx+1, cnt, lotto);
}

void printAllLottoNums(int k) {
  std::vector<int> seq(k);
  for (int i = 0; i < k; i++) {
    std::cin >> seq[i];
  }

  std::vector<int> lotto;
  printLottos(seq, 0, 0, lotto);
}

void solution() {
  int k;
  std::cin >> k;
  while(k > 0) {
    printAllLottoNums(k);
    printf("\n");
    std::cin >> k;
  }
}

int main(void) {
  solution();
  return 0;
}