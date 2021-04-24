#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

tuple<int,int, int> findFood(tuple<int,int> shark, int size, vector<vector<int>> &board) {
  int n = (int)board.size();
  int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
  int y,x;
  queue<tuple<int,int>> Q;
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  vector<tuple<int,int>> pos;
  tie(y,x) = shark;  
  Q.push(shark);
  visit[y][x] = true;
  int dist = 0;
  bool find = false;

  // 최소 거리에 있는 먹이 찾기
  while(!Q.empty()) {
    int len = (int)Q.size();
    dist+=1;
    while(len--) {
      tie(y,x) = Q.front();
      Q.pop();
    
      for (int i = 0; i < 4; i++) {
        int r = y + dr[i];
        int c = x + dc[i];
        if (!(0<=r&&r<n && 0<=c&&c<n) || size < board[r][c] || visit[r][c])
          continue;
        if (board[r][c]!=0 && size > board[r][c]) {
          find = true;
        }
        Q.push(tie(r,c));
        visit[r][c] = true;
      }
    }
    if (find)
      break;
  }

  //최소 거리에 있는 먹이 저장
  while(!Q.empty()) {
    tie(y,x) = Q.front();
    Q.pop();
    
    if (board[y][x] != 0 && board[y][x] < size)
      pos.push_back(tie(y,x));
  }

  if (pos.empty()) return make_tuple(-1,-1,-1);
  
  //최소 거리 먹이 중 가장 위에 있는 것 중 가장 왼쪽에 있는 먹이 찾기
  sort(pos.begin(), pos.end(), [n](tuple<int,int> a, tuple<int,int> b)->bool{
    int ax, ay, bx, by;
    tie(ay, ax) = a;
    tie(by, bx) = b;
    if (ay * n + ax < by * n + bx) return true;
    return false;
  });
  
  tie(y,x) = pos.front();
  return tie(y,x,dist);
}

int solution(tuple<int,int> shark, vector<vector<int>>&board) {
  int n = (int)board.size();
  int y,x,sec = 0, findSec = 0,size=2, cnt=2;

  tie(y,x) = shark;
  board[y][x] = 0;
  int count = 0;
  while(true) {
    tie(y,x,findSec) = findFood(tie(y,x), size, board);
    //cout << y << ", " << x << ": " << findSec << "sec : " << board[y][x] << "fishSize : " << size << "sharkSize\n";
    if (y==-1)
      break;
    count++;
    sec+=findSec;

    board[y][x] = 0;
    
    cnt--;
    if (cnt == 0) {
      size+=1;
      cnt = size;
    }
  }
  
  return sec;
}

int main(void) {
  int n, y, x;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        y = i; x = j;
      }
    }
  }
  cout << solution(tie(y,x),board) << '\n';
  return 0;
}