#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void qPush(queue<pair<int,int> > &q, vector<vector<bool> > &check, int X, int Y, int T) {
  if (X > Y)
      swap(X, Y);

  Y -= X;
  X += X;

  if (!check[X][Y]) {
    check[X][Y] = check[Y][X] = true;
    q.push({X, Y});
  }
}

bool solution(vector<int> stones) {
  int totCnt = stones[0] + stones[1] + stones[2];
  if (totCnt % 3) return false;

  int same = totCnt / 3, X, Y, Z;
  pair<int, int> cntXY = {stones[0], stones[1]};
  // X Y Z -> X Y totCnt-(X+Y)

  vector<vector<bool> > check(totCnt+1, vector<bool>(totCnt, false));
  queue<pair<int,int> > q;

  q.push(cntXY);
  check[cntXY.first][cntXY.second] = true;
  check[cntXY.second][cntXY.first] = true;
  
  while(!q.empty()) {
    cntXY = q.front();
    q.pop();

    if (cntXY.first == same && cntXY.second == same)
      return true;
    
    X = cntXY.first; Y = cntXY.second; Z = totCnt-(cntXY.first+cntXY.second);
    
    qPush(q, check, X, Y, totCnt);
    qPush(q, check, X, Z, totCnt);
    qPush(q, check, Y, Z, totCnt);
  }

  return false;
}

int main(void) {
  vector<int> stones(3);
  cin >> stones[0] >> stones[1] >> stones[2];

  if (solution(stones))
    printf("1\n");
  else
    printf("0\n");
  return 0;
}