#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vvi = vector<vector<int> >;
class position {
public:
  //스도쿠
  bool row[9];
  bool col[9];
  bool block[9];
};

// 1. 문제 잘못 읽어서 몇시간 헤맴
// 2. 초기화 몇개 빼먹어서 몇시간을 헤맴.

position pos[10]; //pos[i]: 숫자 i가 놓여진 위치 정보
vvi map_(9);
bool domino[10][10]; //domino[i][j]: [i j](or [j i]) 도미노의 사용여부


void setPosition(int row, int col, int num, bool val) {
  pos[num].row[row] = pos[num].col[col] = pos[num].block[3*(row/3) + col/3] = val;
}

bool canPut(int row, int col, int num) {
  if (pos[num].row[row] || pos[num].col[col] || pos[num].block[3*(row/3) + col/3])
    return false;
  return true;
}

void print() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d", map_[i][j]);
    }
    printf("\n");
  }
}

void dfs(int idx, bool &endFlag) {
  if (idx == 81) {
    endFlag = true;
    print();
    return;
  }

  int row1 = idx/9;
  int col1 = idx%9;
  
  if (map_[row1][col1] > 0) {//현재 칸에 이미 수가 채워져 있으면 다음 칸 탐색
    dfs(idx+1, endFlag);
    return;
  }


  // printf("----idx: %d----\n", idx);
  // print(idx);
  // printf("----------------\n");


  
  for (int d = 0; d < 2; d++) { //도미노의 0, -90도 회전을 표현
    int row2 = row1 + d;
    int col2 = col1 + (d+1)%2;

    if (!(0<=row2 && row2<9 && 0<=col2 && col2<9))//해당 위치가 map_의 범위를 벗어나는지 체크
        continue;

    if (map_[row2][col2] > 0)//해당 위치에 이미 숫자가 있는지 체크
        continue;

    for (int num1 = 1; num1 < 10; num1++) {
      //num1을 해당 위치에 넣어도 되는지 체크
      if (!canPut(row1, col1, num1))
        continue;

      //num1이 쓰여지는 위치 기록
      setPosition(row1, col1, num1, true);
      map_[row1][col1] = num1;

      for (int num2 = 1; num2 < 10; num2++) {
        if (num1==num2 || domino[num1][num2])//사용한 도미노인지 체크
          continue;

        if (!canPut(row2,col2,num2))//num2를 해당 위치에 넣어도 되는지 체크
          continue;
        
        setPosition(row2, col2, num2, true);
        map_[row2][col2] = num2;
        domino[num2][num1] = domino[num1][num2] = true; //도미노 [num1 num2] [num2 num1] 사용

        dfs(idx+1, endFlag); //다음 칸 탐색
        if (endFlag) return;

        setPosition(row2, col2, num2, false);
        map_[row2][col2] = 0;
        domino[num2][num1] = domino[num1][num2] = false;
      }

      setPosition(row1, col1, num1, false);
      map_[row1][col1] = 0;
    }
  }
}

void init(int n) {
  int num1, num2, row, col;
  string s;

  //position of number 초기화
  for (int num = 1; num < 10; num++) {
    for (int i = 0; i < 9; i++) {
      pos[num].row[i] = pos[num].col[i] = pos[num].block[i] = false;
    }
  }

  //map_ 초기화 & domino 초기화
  for (row = 0; row < 9; ++row) {
    for (col = 0; col < 9; ++col) {
      map_[row][col] = 0;

      if (row == col)
        domino[row+1][col+1] = true;
      else
        domino[row+1][col+1] = false;
    }
  }

  //map_채우기 1
  for (int i = 0; i < n; i++) {
    std::cin >> num1 >> s;
    row = s[0]-'A';
    col = s[1]-'1';
    map_[row][col] = num1;
    setPosition(row, col, num1, true);
    
    std::cin >> num2 >> s;
    row = s[0]-'A';
    col = s[1]-'1';
    map_[row][col] = num2;
    setPosition(row, col, num2, true);

    domino[num1][num2] = domino[num2][num1] = true;
  }

  //map_채우기 2
  for (int i = 1; i <= 9; i++) {
    std::cin >> s;
    row = s[0]-'A';
    col = s[1]-'1';
    map_[row][col] = i;
    setPosition(row, col, i, true);
  }
}

void solve(int cnt) {
  bool endFlag = false;
  printf("Puzzle %d\n", cnt);
  dfs(0, endFlag);
}

void solution() {
  for (int i = 0; i < 9; i++) {
    map_[i].resize(9);
  }

  int n, cnt = 0;
  while(true) {
    std::cin >> n;
    if (n == 0) break;
    init(n);
    solve(++cnt);
  }
}

int main(void) {
  solution();
  return 0;
}