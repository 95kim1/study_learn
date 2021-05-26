#include <iostream>
#include <vector>
#include <queue>
#define vector std::vector
#define pair std::pair
#define queue std::queue

class Game {
  int m_n;
  int m_m;
  vector<vector<int>> m_board;

public:
  /* constructor & init */
  Game();

  bool checkOutside(int &x_y, int &x_x);

  /* find block group & return pairs */
  vector<pair<int,int>> findBlockGroup(int x_y, int x_x, int &x_zeroCnt, vector<vector<int>> &x_visit);
  /* find largest block group */
  vector<pair<int,int>> findLargestBlockGroup();

  /* delete largest group */
  int deleteLargeGroup(vector<pair<int,int>> &xVtr_group);
  /* rotate board */
  void rotateBoard();
  /* operate gravity */
  void operateGravity();

  int solution();
};

Game::Game() {
  std::cin >> m_n >> m_m;
  
  m_board.resize(m_n);
  
  for (vector<int> &row : m_board) {
    row.resize(m_n, -2);
    
    for (int &elem : row)
      std::cin >> elem;
  }
}

bool Game::checkOutside(int &x_y, int &x_x) {
  if (0 <= x_y && x_y < m_n && 0 <= x_x && x_x < m_n)
    return false;
  return true;
}

vector<pair<int,int>> Game::findBlockGroup(int x_y, int x_x, int &x_zeroCnt, vector<vector<int>> &x_visit) {
    int blockNum = m_board[x_y][x_x];
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    vector<pair<int,int>> vtr_resPairs;
    queue<pair<int,int>> que_1;
    
    /* init */
    x_zeroCnt = 0;
    x_visit[x_y][x_x] = blockNum;
    que_1.push({x_y, x_x});
    vtr_resPairs.push_back({x_y, x_x});

    while(!que_1.empty()) {
      int y = que_1.front().first;
      int x = que_1.front().second;
      que_1.pop();

      for (int i = 0; i < 4; i++) {
        int nextY = y + dr[i];
        int nextX = x + dc[i];

        if (checkOutside(nextY, nextX) || x_visit[nextY][nextX] == blockNum)
          continue;

        if (m_board[nextY][nextX] != blockNum && m_board[nextY][nextX] != 0)
          continue;
        
        /* count rainbow colors */
        if (m_board[nextY][nextX] == 0)
          x_zeroCnt++;

        vtr_resPairs.push_back({nextY, nextX});
        que_1.push({nextY, nextX});
        x_visit[nextY][nextX] = blockNum;
      }
    }

    pair<int,int> pair_standard = {x_y, x_x};
    for (pair<int,int> &elem : vtr_resPairs) {
      /* not choose a rainbow colored block */
      if (m_board[elem.first][elem.second] == 0)
        continue;

      if (elem.first < pair_standard.first)
        pair_standard = elem;
      else if (elem.first == pair_standard.first && elem.second < pair_standard.second)
        pair_standard = elem;
    }

    vtr_resPairs.push_back(pair_standard);
    
    return vtr_resPairs;
  }

  vector<pair<int,int>> Game::findLargestBlockGroup() {
    vector<pair<int,int>> vtr_largestGroup;
    vector<pair<int,int>> vtr_group;
    vector<vector<int>> visit(m_n, vector<int>(m_n, 0));
    int zeroCnt = 0;
    int maxZeroCnt = -1;

    for (int y = 0; y < m_n; y++) {
      for (int x = 0; x < m_n; x++) {
        if (m_board[y][x] <= 0 || visit[y][x] > 0)
          continue;

        vtr_group = findBlockGroup(y, x, zeroCnt, visit);
       
        int gSize = vtr_group.size();
        
        if (gSize <= 2)
          continue;

        int lGSize = vtr_largestGroup.size();

        if (lGSize <= 2) {
          vtr_largestGroup = vtr_group;
          maxZeroCnt = zeroCnt;
          continue;
        }

        pair<int,int> &pair_gStd = vtr_group.back();
        pair<int,int> &pair_lGStd = vtr_largestGroup.back();

        /* 큰 그룹 */
        if (gSize > lGSize) {
          vtr_largestGroup = vtr_group;
          maxZeroCnt = zeroCnt; // (이 부분 빼먹어서 많이 헤맸다.)
        }
        else if (gSize == lGSize) {
          /* 무지개 많은 그룹 */
          if (zeroCnt > maxZeroCnt) {
            vtr_largestGroup = vtr_group;
            maxZeroCnt = zeroCnt;   
          }
          else if (zeroCnt == maxZeroCnt) {
            /* 행 번호 가장 큰 그룹 */
            if (pair_gStd.first > pair_lGStd.first) {
              vtr_largestGroup = vtr_group;
            }/* 열 번호 가장 큰 그룹 */
            else if (pair_gStd.first == pair_lGStd.first && pair_gStd.second > pair_lGStd.second) {
              vtr_largestGroup = vtr_group;
            }
          }
        }
      }
    }

    return vtr_largestGroup;
  }

  int Game::deleteLargeGroup(vector<pair<int,int>> &xVtr_group) {
    xVtr_group.pop_back();

    int score = xVtr_group.size();
    score *= score;

    for (pair<int,int> &elem : xVtr_group) {
      m_board[elem.first][elem.second] = -2;
    }

    return score;
  }

  void Game::rotateBoard() {
    vector<vector<int>> board = m_board;
    for (int i = 0; i < m_n; i++) {
      int j = m_n;
      for (int &elem : board[i])
        m_board[--j][i] = elem;
    }
  }

  void Game::operateGravity() {
    auto goDown = [this](int y, int x) {
      int num = this->m_board[y][x];
      this->m_board[y][x] = -2;

      y++;
      while(y < this->m_n && this->m_board[y][x] == -2) {
        y++;
      }
      y--;
      
      this->m_board[y][x] = num;
    };

    for (int x = 0; x < m_n; x++) {
      for (int y = m_n - 1; y >= 0; y--) {
        if (m_board[y][x] == -2 || m_board[y][x] == -1)
          continue;
        goDown(y, x);
      }
    }
  }

  void print(int i, vector<vector<int>> &x_board) {
    std::cout << "print: " << i << '\n';
    for (auto &row : x_board) {
      for (int &elem : row) {
        if (elem == -2)
          printf(" . ");
        else
          printf("%2d ", elem);
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  int Game::solution() {
    int score = 0;
    
    while(true) {
      vector<pair<int,int>> lGroup = findLargestBlockGroup();

      if (lGroup.size() <= 2)
        break;
        
      score += deleteLargeGroup(lGroup);
      
      operateGravity();
      rotateBoard(); 
      operateGravity();
    }

    return score;
  }

  int main(void) {
    Game *ptr_game = new Game();
    std::cout << ptr_game->solution() << '\n';
    delete ptr_game;
    return 0;
  }