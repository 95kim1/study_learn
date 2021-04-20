#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;


bool isAllSame(multiset<int> &stones) {
  vector<int> cur;
  for (int stone : stones)
    cur.push_back(stone);
  if (cur[0] == cur[1] && cur[1] == cur[2])
    return true;
  return false;
}


bool solution(multiset<int> stones) {
  set<multiset<int> > s;
  queue<multiset<int> > q;
  multiset<int> curStones;
  multiset<int> nextStones;
  vector<int> nextStonesVec(3);
  int X, Y;

  q.push(stones);
  s.insert(stones);

  while(!q.empty()) {
    curStones = q.front();
    q.pop();

    if (isAllSame(curStones))
      return true;

    //choose stones
    for (int i = 0; i < 2; i++) {
      for (int j = i+1; j < 3; j++) {
        int idx = 0;
        for (int elem : curStones)
          nextStonesVec[idx++] = elem;
        
        if (nextStonesVec[i] == nextStonesVec[j])
          continue;
        
        X = i; Y = j;
        if (nextStonesVec[X] > nextStonesVec[Y])
          swap(X, Y);
        
        nextStonesVec[Y] -= nextStonesVec[X];
        nextStonesVec[X] *= 2;

        nextStones = {nextStonesVec[0], nextStonesVec[1], nextStonesVec[2]};

        if (s.find(nextStones) != s.end())
          continue;

        q.push(nextStones);
      }
    }
  }

  return false;
}

int main(void) {
  int x, y, z;
  cin >> x >> y >> z;
  multiset<int> stones;
  stones.insert(x);
  stones.insert(y);
  stones.insert(z);

  if (solution(stones))
    printf("1\n");
  else
    printf("0\n");
  return 0;
}