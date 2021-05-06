#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string A, string B) {
  int n = (int)A.length();
  int answer = 0, answer2 = 1;
  vector<int> seq(n, 0);
  vector<int> seq2(n, 0);

  for (int i = 0; i < n; i++) {
    if (A[i] != B[i]) {
      seq[i] = 1;
      seq2[i] = 1;
    }
  }

  seq2[0] = 1 - seq2[0];
  seq2[1] = 1 - seq2[1];
  for (int i = 0; i+1 < n; i++) {
    if (seq[i] == 1) {
      seq[i] = 1 - seq[i];
      seq[i+1] = 1 - seq[i+1];
      if (i+2 < n)
        seq[i+2] = 1 - seq[i+2];
      answer += 1;
    }
    if (seq2[i] == 1) {
      seq2[i] = 1 - seq2[i];
      seq2[i+1] = 1 - seq2[i+1];
      if (i+2 < n)
        seq2[i+2] = 1 - seq2[i+2];
      answer2 += 1;
    }
  }

  if (seq[n-1] == 0 && seq2[n-1] == 0)  
    return (answer < answer2) ? answer : answer2;
  if (seq[n-1] == 0)
    return answer;
  if (seq2[n-1] == 0)
    return answer2;
  return -1;
}

int main(void) {
  int n;
  cin >> n;
  string A, B;
  cin >> A >> B;
  cout << solution(A,B) << '\n';
  return 0;
}