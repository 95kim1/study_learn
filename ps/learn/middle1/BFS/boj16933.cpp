#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#define WALL 1
#define BLANK 0
#define DAY 1
#define NIGHT 0
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

/*
int[][][][]가 아닌 vector<vector<vector<vector<int>>>>로 구현했더니
메모리 초과가 너무 떠서 4차원 정수 배열로 바꾸었다. (메모리 초과로 알고리즘에 문제가 있는 줄 알고 1시간은 넘게 고민했다...)
(벽 부수고 이동 2 문제에서도 vector대신 (3차원) 정수 배열을 썼더니 메모리 소모가 거의 반으로 줄었다.)
(심지어 걸리는 시간도 거의 반으로 줄었다. 756ms -> 376ms, 
std::array를 썼을 때는 int[][][]과 비슷한 메모리를 쓰고 비슷한 시간이 걸렸다.)
*/

int dist[1000][1000][11][2];

int solution(int k, vector<vector<int>> &board) {
  int n = (int)board.size();
  int m = (int)board[0].size();
  int y, x, cnt, day;
  queue<tuple<int,int,int,int>> Q;

  Q.push(make_tuple(0,0,0, DAY));
  dist[0][0][0][DAY] = 1;

  while(!Q.empty()) {
    tie(y, x, cnt, day) = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int r = (i==3) ? y-1 : (i==1) ? y+1 : y;
      int c = (i==2) ? x-1 : (i==0) ? x+1 : x;

      if (!(0<=r&&r<n && 0<=c&&c<m))
        continue;
      
      if (board[r][c] == BLANK && dist[r][c][cnt][1-day] == BLANK) {
        dist[r][c][cnt][1-day] = dist[y][x][cnt][day] + 1;
        Q.push(make_tuple(r,c,cnt,1-day));
      }
      else if (cnt < k && board[r][c] == WALL && dist[r][c][cnt+1][1-day] == BLANK) {
        if (day == DAY) {
          dist[r][c][cnt+1][1-day] = dist[y][x][cnt][day] + 1;
          Q.push(make_tuple(r,c,cnt+1,1-day));
        }
        else if (dist[y][x][cnt][1-day] == BLANK) {
          dist[y][x][cnt][1-day] = dist[y][x][cnt][day]+1;
          Q.push(make_tuple(y,x,cnt,1-day));
        }
      }
    }
    
  }

  int answer = -1;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < 2; j++) {
      if (dist[n-1][m-1][i][j] > 0 && (answer == -1 || answer > dist[n-1][m-1][i][j])) {
        answer = dist[n-1][m-1][i][j];
      }
    }
  }
  return answer;
}

int main(void) {
  int n, m, k;
  cin >> n >> m >> k;
  string str;
  vvi board(n, vi(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d",&board[i][j]);
    }
  }

  cout << solution(k, board) << '\n';

  return 0;
}