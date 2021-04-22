#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <queue>
using namespace std;

int bfs(int r, int c, int id, vector<vector<int>> &board, vector<vector<int>> &group) {
  int cnt = 1, x, y, n = (int)board.size(), m = (int)board[0].size();
  group[r][c] = id;
  queue<tuple<int,int>> Q;
  
  Q.push(tie(r,c));

  while(!Q.empty()) {
    tie(y,x) = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int a = (i == 3) ? y-1 : (i==1) ? y+1 : y;
      int b = (i == 2) ? x-1 : (i==0) ? x+1 : x;
      
      if (!(0<=a&&a<n && 0<=b&&b<m) || group[a][b] != 0 || board[a][b] != 0)
        continue;
      
      cnt++;
      group[a][b] = id;
      Q.push(tie(a,b));
    }
  }

  return cnt;
}

void solution(int n, int m, vector<vector<int> > &board) {
  vector<int> groupCnt;
  vector<vector<int> > group(n, vector<int>(m, 0));

  groupCnt.push_back(0);

  int id = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; j++) {
      if (board[i][j]!=0 || group[i][j]!=0)
        continue;
      groupCnt.push_back(bfs(i,j,id,board,group)); //빈칸 그룹화하기 (각 그룹 번호별로 빈칸 개수 저장)
      id++;
    }
  }

  set<int> tempGroup;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      if (group[i][j]!=0)
        continue;

      for (int d = 0; d < 4; d++) {//인접한 칸 살피기
        int y = (d==3) ? i-1 : (d==1) ? i+1 : i;
        int x = (d==2) ? j-1 : (d==0) ? j+1 : j;
        
        if (!(0<=y&&y<n && 0<=x&&x<m) || group[y][x] == 0)//인접한 칸이 범위 넘거나 벽인 경우 스킵
          continue;

        tempGroup.insert(group[y][x]);//가능한 인접 칸 집합에 저장 (중복 그룹 불허)
      }

      for (int elem : tempGroup) //집합에 저장한 인접 칸에 대해서 앞으로 이동할 수 있는 칸의 개수 저장
        board[i][j] = (board[i][j] + groupCnt[elem])%10;
      tempGroup.clear();
    }
  }
}

int main(void) {
  int n, m;
  string str;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      board[i][j] = str[j]-'0';
    }
  }

  solution(n,m,board);

  for (vector<int> &rows : board) {
    for (int elem : rows) {
      printf("%d", elem);
    }
    printf("\n");
  }

  return 0;
}