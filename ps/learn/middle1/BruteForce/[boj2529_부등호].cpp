#include <iostream>
#include <string>

void nextPermutation(std::string::iterator beginIter, std::string::iterator endIter) {
  std::string::iterator curIter = endIter-1;
  
  while(curIter != beginIter && *curIter <= *(curIter-1)) {curIter--;}
  if (curIter==beginIter)
    return;
  curIter--;
  
  std::string::iterator tempIter = curIter+1;
  while(tempIter != endIter && *curIter < *tempIter) {tempIter++;}
  tempIter--;

  *curIter ^= *tempIter;
  *tempIter ^= *curIter;
  *curIter ^= *tempIter;
  
  curIter++;
  tempIter = endIter-1;
  while(curIter < tempIter) {
    *curIter ^= *tempIter;
    *tempIter ^= *curIter;
    *curIter ^= *tempIter;
    curIter++;
    tempIter--;
  }
}

void prevPermutation(std::string::iterator beginIter, std::string::iterator endIter) {
  std::string::iterator curIter = endIter-1;
  
  while(curIter != beginIter && *curIter >= *(curIter-1)) {curIter--;}
  if (curIter==beginIter)
    return;
  curIter--;
  
  std::string::iterator tempIter = curIter+1;
  while(tempIter != endIter && *curIter > *tempIter) {tempIter++;}
  tempIter--;

  
  *curIter ^= *tempIter;
  *tempIter ^= *curIter;
  *curIter ^= *tempIter;
  
  curIter++;
  tempIter = endIter-1;
  while(curIter < tempIter) {
    *curIter ^= *tempIter;
    *tempIter ^= *curIter;
    *curIter ^= *tempIter;
    curIter++;
    tempIter--;
  }
} 

bool compare(std::string &symbol, std::string &nums) {
  for (int i = 0; i < (int)symbol.length(); i++) {
    if (symbol[i] == '>') {
      if (nums[i] <= nums[i+1])
        return false;
    }
    else {
      if (nums[i] >= nums[i+1])
        return false;
    }
  }
  return true;
}

int main(void) {
  int n;
  char c;
  std::cin >> n;
  std::string symbol;
  std::string maxN, minN;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    symbol.push_back(c);
    maxN.push_back((9 - i) + '0');
    minN.push_back(i + '0');
  }
  maxN.push_back((9 - n) + '0');
  minN.push_back(n + '0');

  while(!compare(symbol, maxN)) {
    prevPermutation(maxN.begin(), maxN.end());
  }
  std::cout << maxN << '\n';
  while(!compare(symbol, minN)) {
    nextPermutation(minN.begin(), minN.end());
  }
  std::cout << minN << '\n';

  return 0;
}