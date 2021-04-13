#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int dfsTetro(vector<vector<int> > &map_, int depth, int r, int c, vector<vector<bool> > &visit, int sum = 0) {
  if (depth == 3) {// 4번째 타일까지 모두 더했으면 해당 값 반환
    return sum;
  }

  visit[r][c] = true;

  int Msum = 0;

  for (int i = 0 ; i < 4; i++) {// 현재 타일에서 이어진 4부분 탐색
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0<=R && R<(int)map_.size() && 0<=C && C<(int)map_[0].size()) || visit[R][C])
      continue;

    int tempN = dfsTetro(map_, depth+1, R, C, visit, sum+map_[R][C]);  
    if (tempN > Msum)//현재까지 구한 값들 중 큰 값 고르기
      Msum = tempN;
  }

  visit[r][c] = false;
  
  return Msum;
}

int crossSum(vector<vector<int> > &map_, int r, int c) {
  int tot = map_[r][c];
  int cnt = 0;
  for (int i = 0; i < 4; i++) {// 현재 타일과 이어진 4부분 더하기(더할 수 없는 부분은 제외)
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0<=R && R<(int)map_.size() && 0<=C && C<(int)map_[0].size()))
      continue;
    cnt++;
    tot += map_[R][C];
  }

  if (cnt < 3) return 0; // 현재 타일과 3개 미만의 타일이 이어옂 있다면 0 반환
  if (cnt == 3) return tot; //현재 타일과 3개의 타일만이 이어져 있다면 그대로 반환

  int Msum = 0;
  for (int i = 0; i < 4; i++) { // 현재 타일과 이어진 4부분 중 하나를 제외했을 때 최대값 선택
    int R = r + dr[i];
    int C = c + dc[i];
    int temp = tot - map_[R][C];
    if (Msum < temp)
      Msum = temp;
  }
  return Msum;
}

int main(void) {
  int r, c, temp;
  cin >> r >> c;
  vector<vector<int> > map_(r);
  vector<vector<bool> > visit(r);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> temp;
      map_[i].push_back(temp);
      visit[i].push_back(false);
    }
  }

  int Msum = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      temp = dfsTetro(map_, 0, i, j, visit, map_[i][j]);
      if (Msum < temp) Msum = temp;
      temp = crossSum(map_, i, j);
      if (Msum < temp) Msum = temp;
    }
  }

  printf("%d\n", Msum);

  return 0;
}