#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

bool dropOrNot(vector<string> &map_, int r, int c) {
  if (0 <= r && r < (int)map_.size() && 0 <= c && c < (int)map_[0].length())
    return false;
  return true;
}

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int dropOneCoin(vector<string> &map_, int depth, pair<int,int> coin1, pair<int, int> coin2) {
  if (depth == 11) {
    return -1;
  }

  // coin1, coin2 떨어졌는지 여부
  bool drop1 = dropOrNot(map_, coin1.first, coin1.second);
  bool drop2 = dropOrNot(map_, coin2.first, coin2.second);
  
  if (drop1 && drop2) return -1; //둘 다 떨어지면 탈락
  if (drop1 || drop2) return depth; //둘 중 하나 떨어지면 성공

  int cnt = -1;
  for (int i = 0; i < 4; i++) {
    int R1 = coin1.first + dr[i], R2 = coin2.first + dr[i];
    int C1 = coin1.second + dc[i], C2 = coin2.second + dc[i];
    
    if (!dropOrNot(map_, R1, C1) && map_[R1][C1] == '#') {//코인이 이동할 곳에 벽이 있음.
      R1 = coin1.first; C1 = coin1.second;
    }
    
    if (!dropOrNot(map_, R2, C2) && map_[R2][C2] == '#') {
      R2 = coin2.first; C2 = coin2.second;
    }
      
    // 성공 할 때까지의 시간의 최소값 저장
    int temp = dropOneCoin(map_, depth+1, make_pair(R1,C1), make_pair(R2, C2));
    
    if (temp == -1)
      continue;

    if (cnt == -1 || temp < cnt) {
      cnt = temp;
    }
  }

  return cnt;
}

int main(void) {
  int r, c;
  cin >> r >> c;
  vector<string> map_(r);
  pair<int, int> coin1;
  coin1.first = -1;
  pair<int, int> coin2;
  for (int i = 0; i < r; i++) {
    cin >> map_[i];
    for (int j = 0; j < c; j++) {
      if (map_[i][j] == 'o') {
        if (coin1.first == -1)
          coin1 = make_pair(i, j);
        else
          coin2 = make_pair(i, j);
      }
    }
  }

  printf("%d\n", dropOneCoin(map_, 0, coin1, coin2));

  return 0;
}