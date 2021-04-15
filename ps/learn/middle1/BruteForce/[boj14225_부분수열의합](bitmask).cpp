#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;


void init(vi &S, bool numsMade[]) {
  int n, sum = 0;
  cin >> n;
  S.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
    sum += S[i];
  }

  for (int i = 0; i <= sum; i++) {
    numsMade[i] = false;
  }
}

void solution() {
  vi S;
  bool numsMade[2000001];

  init(S, numsMade);

  const int maxMask = (1<<(int)S.size()) - 1;
  int sumNums = 0;

  for (int mask = 1; mask <= maxMask; mask++) {//mask : 부분수열
    sumNums = 0;
    for (int i = 0; i < (int)S.size(); i++) {//i : S의 인덱스
      if(!(mask & (1<<i))) //mask에 S[i]를 선택하지 않았다면 스킵
        continue;      
      sumNums += S[i];
    }
    numsMade[sumNums] = true;
  }

  for (int num = 1; num <= 20000000; num++) {
    if (numsMade[num])
      continue;
    printf("%d\n", num);
    break;
  }
}

int main(void) {
  solution();
  return 0;
}