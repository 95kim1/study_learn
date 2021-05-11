#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BOARD {
  int n;
  vector<string> board;

public:
  int answer;

  void init() {
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> board[i];
    }
    answer = n*n;
  }

  int min_(int x, int y) {
    return (x>y) ? y : x;
  }

  void flip(char& c) {
    c = (c=='T')?'H':'T';
  }

  void flips(int r) {
    if (r == n) {
      int cntT = 0;
      for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          if (board[j][i] == 'T')
            cnt++;
        }
        cntT += min_(cnt, n-cnt);
      }

      if (answer > cntT)
        answer = cntT;

      return;
    }

    flips(r+1);
    
    for (int i = 0; i < n; i++)
      flip(board[r][i]);
    
    flips(r+1);

    for (int i = 0; i < n; i++)
      flip(board[r][i]);
  }

};

int main(void) {
  BOARD board;
  board.init();
  board.flips(0);  
  cout << board.answer << '\n';
  return 0;
}