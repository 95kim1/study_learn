#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int solution(int n, int m, vector<string> &board) {
  int sy=-1, sx, ey, ex;
  queue<tuple<int,int>> Q;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      if (board[i][j] == 'C') {
        if (sy==-1) {
          sy = i; sx = j;
        }
        else {
          ey = i; ex = j;
        }
      }
    }
  }  

  int dx[] = {0,1,0,-1}, dy[] = {1, 0, -1, 0};

  Q.push(tie(sy,sx));
  dist[sy][sx] = 0;
  
  int y,x;
  while(!Q.empty()) {
    tie(y,x) = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int Y = y + dy[i];
      int X = x + dx[i];
      while(0<=Y&&Y<n && 0<=X&&X<m) {
        if (board[Y][X] == '*')
          break;

        if (dist[Y][X]==-1) {  
          dist[Y][X] = dist[y][x] + 1;
          Q.push(tie(Y,X));
        }

        Y+=dy[i];
        X+=dx[i];
      }
    }
  }


  return dist[ey][ex]-1;
}

int main(void) {
  int n, m;
  cin >> m >> n;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  cout << solution(n,m,board) << '\n';

  return 0;
}