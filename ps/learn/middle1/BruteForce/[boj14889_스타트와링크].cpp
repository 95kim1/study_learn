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

int calculateDiff(std::vector<std::vector<int> > &abMap, std::vector<int> &tSeq) {
  int diff = 0;
  int n = (int)abMap.size();
  int tnum1, tnum2; //team number
  int team1Ab = 0, team2Ab = 0; //sum of player's ability of team 1, 2
  for (int i = 0; i < n-1 ; i++) {
    tnum1 = tSeq[i];
    for (int j = i+1; j < n; j++) {
      tnum2 = tSeq[j];
      if (tnum1 != tnum2 || i == j) continue;
      if (tnum1 == 0) {
        team1Ab += abMap[i][j] + abMap[j][i];
      }
      else {
        team2Ab += abMap[i][j] + abMap[j][i];
      }
    }
  }
  diff = team1Ab - team2Ab;
  if (diff < 0) diff = -diff;
  return diff;
}

void solution() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > abilityMap(n);
  std::vector<int> teamSeq(n, 1); // idx: player number, teamSeq[idx]: player's team number
  for (int i = 0; i < n; i++) {
    for (int temp, j = 0; j < n; j++) {
      std::cin >> temp;
      abilityMap[i].push_back(temp);
    }
  }

  n /= 2;
  for (int i = 0; i < n; i++) {
    teamSeq[i] = 0;
  }
  n *= 2;

  int mdiff = 40000;
  do {
    int diff = calculateDiff(abilityMap, teamSeq);
    if (mdiff > diff)
      mdiff = diff;
  } while(nextPermutation(teamSeq.begin(), teamSeq.end()));
  //ex) teamSeq : "00001111" -> "00011101" -> "00011110" -> ... -> "11110000"

  printf("%d\n", mdiff);
}

int main(void) {
  solution();
  return 0;
}