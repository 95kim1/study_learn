#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#define N 8
using namespace std;


int solution(vector<string>&board) {
  int answer = 0;
  int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  int y, x;
  queue<tuple<int,int>> Q;

  Q.push(make_tuple(N-1,0));

  while(!Q.empty()) {
    int len = (int)Q.size();
    while(len--) {
      tie(y,x) = Q.front();
      Q.pop();

      if (y==0 && x==N-1)
        return 1;

      for (int i = 0; i < 9; i++) {
        //캐릭터 위치
        int r = y + dr[i];
        int c = x + dc[i];

        if (!(0<=r&&r<N && 0<=c&&c<N) || board[r][c] == '#' || (r > 0 && board[r-1][c] == '#'))
          continue;
        
        Q.push(tie(r,c));
      }
    }

    for (int i = N-1; i > 0; i--) {
      for (int j = 0; j < N; j++) {
        board[i][j] = board[i-1][j];
      }
    }
    for (int j = 0; j < N; j++) {
      board[0][j] = '.';
    }
  }

  return answer;
}

int main(void) {
  vector<string> board(8);
  for (int i = 0; i < 8; i++) {
    cin >> board[i];
  }
  cout << solution(board) << '\n';
  return 0;
}