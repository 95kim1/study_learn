#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;

int init(vi &words) {
  int n, k;
  string tempStr;
  cin >> n >> k;
  words.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> tempStr;

    words[i] = 0;
    for (char c : tempStr) {
      words[i] |= (1 << (c-'a'));
    }
  }
  return k;
}

int dfs(int index, int k, int mask, vi &words) {
  if (k < 0) {//K개 넘개 단우를 배우는 경우
    return 0;
  }
  if (index == 26) {//모든 알파벳에 대해서 배울지에 대한 선택을 마친 경우
    int cnt = 0;
    for (int word : words) {
      // word: "abd..." == ...1011,  (~mask & ((1<<26)-1))의 안 배운 부분이 1  "abd..." == ...0100
      // 따라서 &연산을 해서 0이 아닌 값이 나오면 word에 있는 알파벳 중 배우지 않은 알파벳이 있다는 의미
      if (word & (~mask & ((1<<26) - 1)))
        continue;
      cnt++;
    }
    return cnt;
  }

  
  int cnt = dfs(index+1, k-1, mask|(1<<index), words);
  
  if (index!=0 && index!='n'-'a' && index!='t'-'a' && index!='i'-'a' && index!='c'-'a') {
    int temp = dfs(index+1, k, mask, words);
    if (cnt < temp)
      return temp;
    return cnt;
  }
  
  return cnt;
}

void solution() {
  int k;
  vi words;
  
  k = init(words);

  if (k<5) {
    printf("0\n");
    return;
  }
  printf("%d\n", dfs(0, k, 0, words));
}

int main(void) {
  solution();
  return 0;
}