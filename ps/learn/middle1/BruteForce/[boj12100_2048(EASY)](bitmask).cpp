/*
1. init
loop start
2. 움직임 배열 만들기
3. 움직임 배열에 맞게 움직이기
  3-1. 5번 움직이기
  3-2. 최대값 찾기
4. 최대값 갱신
loop end
5. 최대값 출력
*/
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi >;
using vvb = vector<vector<bool> >;


void init(vvi &board) {
  int n;
  cin >> n;
  board.resize(n);
  for (int i = 0; i < n; i++) {
    board[i].resize(n);
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
}

vi makeDirSet(int dirBits) {
  vi dirSet(5);
  for (int i = 0; i < 5; i++) {
    dirSet[i] = dirBits & 3;
    dirBits >>= 2;
  }
  return dirSet;
}

int maxBlock(vvi &board) {
  int block = 0;
  for (vi rows : board) {
    for (int elem : rows) {
      if (block < elem)
        block = elem;
    }
  }
  return block;
}

void moveUp(vvi &board) {
  int n = (int)board.size();
  vvb change(n);
  for (int i = 0; i < n; i++) {
    change[i].resize(n, false);
  }

  for (int row, col = 0; col < n; col++) {
    row = 0;
    int r = row+1;
    while(row+1 < n) {
      while(r < n && board[r][col] == 0) {r++;}
      if (r == n) {
        break;
      }

      if (board[row][col] == 0) {
        board[row][col] = board[r][col];
        board[r][col] = 0;
      }
      else if (board[row][col] == board[r][col] && !change[row][col]) {
        //합치기
        change[row][col] = true;
        board[row][col] *= 2;
        board[r][col] = 0;
        row++;
      }
      else if (row+1 == r) {
        row++; r++;
      }
      else {
        board[row+1][col] = board[r][col];
        board[r][col] = 0;
        row++;
      }
    }
  }
}

void moveRight(vvi &board) {
  int n = (int)board.size();
  vvb change(n);
  for (int i = 0; i < n; i++) {
    change[i].resize(n, false);
  }

  for (int col, row = 0; row < n; row++) {
    col = n-1;
    int c = col-1;
    while(col-1 >= 0) {
      while(c >= 0 && board[row][c] == 0) {c--;}
      if (c < 0) {
        break;
      }

      if (board[row][col] == 0) {
        board[row][col] = board[row][c];
        board[row][c] = 0;
      }
      else if (board[row][col] == board[row][c] && !change[row][col]) {
        //합치기
        change[row][col] = true;
        board[row][col] *= 2;
        board[row][c] = 0;
        col--;
      }
      else if (col-1 == c) {
        col--; c--;
      }
      else {
        board[row][col-1] = board[row][c];
        board[row][c] = 0;
        col--;
      }
    }
  }
}

void moveDown(vvi &board) {
  int n = (int)board.size();
  vvb change(n);
  for (int i = 0; i < n; i++) {
    change[i].resize(n, false);
  }

  for (int row, col = 0; col < n; col++) {
    row = n - 1;
    int r = row-1;
    while(row-1 >= 0) {
      while(r >= 0 && board[r][col] == 0) {r--;}
      if (r < 0) {
        break;
      }

      if (board[row][col] == 0) {
        board[row][col] = board[r][col];
        board[r][col] = 0;
      }
      else if (board[row][col] == board[r][col] && !change[row][col]) {
        //합치기
        change[row][col] = true;
        board[row][col] *= 2;
        board[r][col] = 0;
        row--;
      }
      else if (row-1 == r) {
        row--; r--;
      }
      else {
        board[row-1][col] = board[r][col];
        board[r][col] = 0;
        row--;
      }
    }
  }
}

void moveLeft(vvi &board) {
  int n = (int)board.size();
  vvb change(n);
  for (int i = 0; i < n; i++) {
    change[i].resize(n, false);
  }

  for (int col, row = 0; row < n; row++) {
    col = 0;
    int c = col+1;
    while(col+1 < n) {
      while(c < n && board[row][c] == 0) {c++;}
      if (c == n) { //[col,...],c: [200..00]
        break;
      }
      
      if (board[row][col] == 0) {//[col,c,..]: [020..] -> [col,c,..]: [200..]
        board[row][col] = board[row][c];
        board[row][c] = 0;
      }
      else if (board[row][col] == board[row][c] && !change[row][col]) {//[col, ,c,..]: [2020..] -> [,col,c,..] [400..]
        //합치기
        change[row][col] = true;
        board[row][col] *= 2;
        board[row][c] = 0;
        col++;
      }
      else if (col+1 == c) {//[col,c,..]: [240..] -> [,col,c,..] [240..]
        col++; c++;
      }
      else {//[col, ,c..]: [2040..] -> [,col&c,..]: [2400..]
        board[row][col+1] = board[row][c];
        board[row][c] = 0;
        col++;
      }
    }
  }
}

// void print(vvi &board) {
//   for (int i = 0; i < (int)board.size(); i++) {
//     for (int j = 0; j < (int)board.size(); j++) {
//       printf("%2d ", board[i][j]);
//     }
//     printf("\n");
//   }
// }

int moveBlocks(vvi board, vi &dirSet) {
  for (int dir : dirSet) {
    switch(dir) {
      case 0:
        moveUp(board);
        break;
      case 1:
        moveRight(board);
        break;
      case 2:
        moveDown(board);
        break;
      case 3: 
        moveLeft(board);
        break;
    }
    //print(board);
  }
  return maxBlock(board);//return max num in board
}

void solution() {
  vvi board;
  vi dirSet;

  init(board);

  int block = 0, temp;

  for (int i = 0; i < 1024; i++) {
    dirSet = makeDirSet(i);//direction set
    
    temp = moveBlocks(board, dirSet);//move five times and get max number
    
    if (temp > block)
      block = temp;
  }

  printf("%d\n", block);
}

int main(void) {
  solution();
  return 0;
}