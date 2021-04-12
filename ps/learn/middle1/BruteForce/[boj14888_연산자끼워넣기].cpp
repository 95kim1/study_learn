#include <iostream>
#include <vector>

bool nextPermutation(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd) {
  std::vector<int>::iterator itCur = itEnd-1;
  while(itCur != itBegin && *(itCur-1) >= *itCur) {itCur--;}
  if (itCur == itBegin) return false;
  itCur--;

  std::vector<int>::iterator itTemp = itCur+1;
  while(itTemp != itEnd && *itCur < *itTemp) {itTemp++;}
  itTemp--;

  *itCur ^= *itTemp;
  *itTemp ^= *itCur;
  *itCur ^= *itTemp;

  itCur++;
  itTemp = itEnd - 1;
  while(itCur < itTemp) {
    *itCur ^= *itTemp;
    *itTemp ^= *itCur;
    *itCur ^= *itTemp;
    itCur++; itTemp--;
  }
  return true;
}

int calculate(std::vector<int> &nums, std::vector<int> &operators) {
  int num = nums[0];
  for (int i = 0; i < (int)operators.size(); i++) {
    switch (operators[i]) {
      case 0:
        num += nums[i+1];
        break; 
      case 1:
        num -= nums[i+1];
        break;
      case 2:
        num *= nums[i+1];
        break;
      case 3:
        num /= nums[i+1];
        break;
    }
  }
  return num;
}

void solution() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  std::vector<int> operators; //0 : +, 1 : -, 2 : *, 3 : /
  for (int cnt, i = 0 ; i < 4; i++) {
    std::cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      operators.push_back(i);
    }
  }

  int Mnum = -100000000, mnum = 100000000;
  do {
    int temp = calculate(nums, operators);
    if (Mnum < temp) Mnum = temp;
    if (mnum > temp) mnum = temp;
  } while(nextPermutation(operators.begin(), operators.end()));

  printf("%d\n%d\n", Mnum, mnum);
}

int main(void) {
  solution();
  return 0;
}