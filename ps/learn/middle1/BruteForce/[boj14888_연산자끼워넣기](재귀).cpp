#include <iostream>
#include <vector>
#include <utility>


std::pair<int,int> solve(std::vector<int> &seqN, int idx, int tempRes, int add, int sub, int mul, int div) {
  if (idx == (int)seqN.size())
    return std::make_pair(tempRes, tempRes);

  std::vector<std::pair<int, int> > v;
  if (add > 0) {
    v.push_back(solve(seqN, idx+1, tempRes + seqN[idx], add-1, sub, mul, div));
  }  
  if (sub > 0) {
    v.push_back(solve(seqN, idx+1, tempRes - seqN[idx], add, sub-1, mul, div));
  }
  if (mul > 0) {
    v.push_back(solve(seqN, idx+1, tempRes * seqN[idx], add, sub, mul-1, div));
  }
  if (div > 0) {
    v.push_back(solve(seqN, idx+1, tempRes / seqN[idx], add, sub, mul, div-1));
  }

  std::pair<int, int> tempPair;
  tempPair.first = v[0].first; tempPair.second = v[0].second;
  for (int i = 1; i < (int)v.size(); i++) {
    if (tempPair.first < v[i].first)
      tempPair.first = v[i].first;
    if (tempPair.second > v[i].second) {
      tempPair.second = v[i].second;
    }
  }

  return tempPair;
}

int main(void) {
  int n;
  std::cin >> n;
  int operators[4];
  std::vector<int> nums(n);
  for (int i= 0; i < n; i++) {
    std::cin >> nums[i];
  }
  for (int i = 0; i  < 4; i++) {
    std::cin >> operators[i];
  }

  std::pair<int, int> pr = solve(nums, 1, nums[0], operators[0], operators[1], operators[2], operators[3]);
  
  printf("%d\n%d\n", pr.first, pr.second);

  return 0;
}