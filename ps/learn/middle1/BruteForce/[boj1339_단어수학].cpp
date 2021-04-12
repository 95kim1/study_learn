#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool prevPermutation(vector<int>::iterator itBegin, vector<int>::iterator itEnd) {
  vector<int>::iterator itCur = itEnd - 1;
  while(itCur != itBegin && *itCur >= *(itCur-1)) {itCur--;}
  if (itCur == itBegin)
    return false;
  itCur--;

  vector<int>::iterator itTemp = itCur+1;
  while(itTemp != itEnd && *itCur > *itTemp) {itTemp++;}
  itTemp--;

  *itCur ^= *itTemp;
  *itTemp ^= *itCur;
  *itCur ^= *itTemp;

  itCur++;
  itTemp = itEnd-1;
  while(itCur < itTemp) {
    *itCur ^= *itTemp;
    *itTemp ^= *itCur;
    *itCur ^= *itTemp;
    itCur++; itTemp--;
  }
  return true;
}

void init(vector<string> &setOfStrings, string &letters, vector<int> &alphabet, vector<int> &seq){
//init
  for (int i = 0; i < (int)setOfStrings.size(); i++) {
    std::cin >> setOfStrings[i];
    for (int j = 0; j < (int)setOfStrings[i].size(); j++) {
      if (alphabet[setOfStrings[i][j]] != -1)
        continue;
      alphabet[setOfStrings[i][j]] = 0;
      letters.push_back(setOfStrings[i][j]);
    }
  }
  for (int i = 0; i < (int)letters.length(); i++) {
    seq.push_back(9-i);
  }
}

long long sumOfStringsInInt(vector<string> &setOfStrings, string &letters, vector<int> &alphabet, vector<int> &seq) {
  long long num = 0;

  for (int i = 0; i < (int)seq.size(); i++) {
    alphabet[letters[i]] = seq[i];
  }

  for (int i = 0; i < (int)setOfStrings.size(); i++) {
    string strSeq = setOfStrings[i];
    int b = 1;
    for (int j = (int)strSeq.length()-1; j>=0; j--) {
      num += b * alphabet[strSeq[j]];
      b *= 10;
    }
  }

  return num;
}

void solution() {
  int size;
  std::cin >> size;
  vector<string> setOfStrings(size); // {"ABC", "DBEFG", ...}
  string letters; // "ABCDEFG"
  vector<int> seq; // {9,8,7,6,5,4,3}
  vector<int> alphabet(256, -1); // mapping 'A' -> number
  
  // to input into setOfStrings
  // setting letters and seq
  init(setOfStrings, letters, alphabet, seq); 
  
  // every case of seq (permutation)
  long long num = 0;
  do {
    // sum of words(setOfStrings) with seq
    long long temp = sumOfStringsInInt(setOfStrings, letters, alphabet, seq);
    if (num < temp)
      num = temp;
  } while(prevPermutation(seq.begin(), seq.end()));
  
  std::cout << num << '\n';
}

int main(void) {
  solution();
  return 0;
}