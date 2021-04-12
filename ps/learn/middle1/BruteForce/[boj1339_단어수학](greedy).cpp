#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
  if (a.second > b.second) 
    return true;
  return false;
}

void init(vector<string> &setOfStrings, int size, vector<pair<char, int> > &seqLetters){
  vector<int> alphabetPriority(256, 0);
  string letters;
  string str;
//init
  for (int i = 0; i < size; i++) {
    std::cin >> str;
    setOfStrings.push_back(str);
    for (int b = 1, j = (int)str.length()-1; j >= 0; j--, b*=10) {
      if (alphabetPriority[str[j]] == 0) {
        letters.push_back(str[j]);
      }
      alphabetPriority[str[j]] += b;
    }
  }

  for (int i = 0; i < (int)letters.length(); i++) {
    seqLetters.push_back(make_pair(letters[i], alphabetPriority[letters[i]]));
  }

  sort(seqLetters.begin(), seqLetters.end(), compare);
}

long long sumStrings(vector<string> &setOfStrings, vector<pair<char, int> > &seqLetters) {
  vector<int> alphabet(256, 0);
  for (int i = 0; i < (int)seqLetters.size(); i++) {
    alphabet[seqLetters[i].first] = (9-i);
  }
  long long num = 0;
  for (int i = 0; i < (int)setOfStrings.size(); i++) {
    int b = 1;
    for (int j = (int)setOfStrings[i].length() - 1; j >= 0; j--) {
      num += alphabet[setOfStrings[i][j]] * b; //priority = sum of "10^(number of digit - 1)"
      b*=10;
    }
  }
  return num;
}

void solution() {
  int size;
  std::cin >> size;
  vector<string> setOfStrings; // {"ABC", "DBEFG", ...}
  vector<pair<char, int> > seqLetters;
  
  // to input into setOfStrings
  // setting seqLetters; (higher digit character : higher number)
  init(setOfStrings, size, seqLetters); 
  
  std::cout << sumStrings(setOfStrings, seqLetters) << '\n';
}

int main(void) {
  solution();
  return 0;
}