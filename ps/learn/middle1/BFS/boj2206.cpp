#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define WALL 1
#define BLANK 0
using namespace std;

//정점의 정보로 구성된 map을 가지고 있자.
//정점이 (row, col, cntBreak) 이므로  distanceMap[row][col][cntBreak]와 같은 map이 필요하다.
//distanceMap[row][col] 과  breakCntMap[row][col]을 따로 할 경우  정점 (row,col,cntBreak)에 맵핑되는 distance 정보를 가질 수 없다.
// 이유: (row,col,0), (row,col,1) 이 두개에 대해서 서로 다른 distance를 맵핑할 수 없다.(1:1 맵핑 불가)
//      1:1로 맵핑해야 되는 이유는 만약 many:1 이라면 나중에 맵핑되어 있는 정보가 (row,col,0)의 정보인지, (row,col,1)의 정보인지 알 수 없기 때문이다.
//      from(row-1,col,0)to(row,col) from(row,col-1,1)to(row,col)이후에 distanceMap[row][col]가 같은 경우 이 둘을 동시에 처리할 수 있다면 상관없지만
//      BFS 특성상 동시에 처리할 수 없기 때문에 distanceMap[row][col]를 구분할 필요가 있다. (distanceMap[row][col]--1:1--breakCntMap[row][col]이므로 구분 불가)
//      (큐에서 첫번째 경우를 뽑고 한참 후에 두번째 경우를 뽑아야 하는 경우에 동시에 처리할 수 없다.)
//      (첫번째 경우에 대해서 처리하고 두번째 경우에서 첫번째 경우에 대한 distanceMap[row][col]를 갱신, 이후에 첫번째 경우에 대한 distanceMap[row][col]이 필요할 때 접근 불가)


//      -> 값을 갱신할 때 나중에 다시 쓰이는지 꼭 생각해보기
//      -> 그래프 혹은 BFS DFS등 탐색의 경우 정점이 뭔지 생각하고 해당 정점에 1:1로 맵핑되는 자료구조 생각해보기

int solution(vector<string> map_) {
  int x, y, w, rowSize = (int)map_.size(), colSize = (int)map_[0].length();
  queue<tuple<int,int,int> > Q;
  vector<vector<int> > board(rowSize, vector<int>(colSize));
  vector<vector<vector<int> > > dist(rowSize, vector<vector<int> >(colSize, vector<int>(2, 0)));

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      if (map_[i][j]=='0')
        board[i][j] = BLANK;
      else
        board[i][j] = WALL;
    }
  }

  x = 0;
  Q.push(tie(x,x,x));
  dist[x][x][0] = 1;
  dist[x][x][1] = 1;
  while(!Q.empty()) {
    tie(y,x,w) = Q.front();
    Q.pop();

    //cout << y << ", " << x << ", " << dist << ", " << wall << '\n';

    for (int i = 0; i < 4; i++) {
      int r = (i==3) ? y-1 : (i==1) ? y+1 : y;
      int c = (i==2) ? x-1 : (i==0) ? x+1 : x;
      if (!(0<=r&&r<rowSize&&0<=c&&c<colSize))
        continue;
      int ww = w;
      if (board[r][c] == BLANK && dist[r][c][ww] == BLANK) {// [? -> 빈칸] 이고 빈칸에 방문한 적이 없으면
        dist[r][c][ww] = dist[y][x][ww] + 1;
        Q.push(tie(r,c,ww));
      }
      else if (ww == BLANK && board[r][c] == WALL && dist[r][c][WALL] == BLANK) {
        // [벽 한 번도 안 깸 -> 벽] 이고 아직 방문 안했으면
        dist[r][c][WALL] = dist[y][x][BLANK] + 1;
        ww = WALL; 
        Q.push(tie(r,c,ww));
      }
      
    }
  }

  int wall = dist[rowSize-1][colSize-1][1];
  int blank = dist[rowSize-1][colSize-1][0];
  int answer = -1;
  if (wall != 0 && blank != 0)
    answer = (wall < blank) ? wall : blank;
  else if (wall == 0 && blank != 0)
    answer = blank;
  else if (wall != 0 && blank == 0)
    answer = wall;

  return answer;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }

  cout << solution(board) << '\n';

  return 0;
}