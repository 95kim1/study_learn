#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using pbb = pair<bool, bool>;
using vi = vector<int>;
using vs = vector<string>;

class MAP_ {
public:
  int n, m;
  vs map;
  pii red;
  pii blue;
  pii hole;
};

void init(MAP_ &MAP) {
  cin >> MAP.n >> MAP.m;
  MAP.map.resize(MAP.n);
  for (int i = 0; i < MAP.n; i++) {
    cin >> MAP.map[i];
    for (int j = 0; j < MAP.m; j++) {
      if (MAP.map[i][j] == 'R')
        MAP.red = make_pair(i,j);
      else if (MAP.map[i][j] == 'B')
        MAP.blue = make_pair(i,j);
      else if (MAP.map[i][j] == 'O')
        MAP.hole = make_pair(i,j);
    }
  }
}

vi makeDirSet(int dirMask) {
  vi dirSet(10);
  for (int i = 0; i < 10; i++) {
    dirSet[i] = dirMask & 3;
    dirMask = dirMask >> 2;
  }
  return dirSet;
}

bool isValidDirSet(vi dirSet) {
  for (int i = 0; i < 9; i++) {
    if (dirSet[i] == dirSet[i+1] || dirSet[i] == (dirSet[i+1]+2)%4)
      return false;
  }
  return true;
}

pbb moveURDL(MAP_ &MAP, int dx, int dy) {
  pbb holeRB = make_pair(false, false);
  pbb moveRB = make_pair(true, true);
  int rx, ry, bx, by;
  while(moveRB.first || moveRB.second) {
    rx = MAP.red.first+dx; ry = MAP.red.second+dy;
    //red
    switch(MAP.map[rx][ry]) {
      case '#':
      case 'B': {
        moveRB.first = false;
        break;
      }
      case 'O': {
        if (!holeRB.first)
          MAP.map[MAP.red.first][MAP.red.second] = '.';
        holeRB.first = true;
        moveRB.first = false;
        break;
      }
      case '.': {
        char temp = MAP.map[rx][ry];
        MAP.map[rx][ry] = MAP.map[MAP.red.first][MAP.red.second];
        MAP.map[MAP.red.first][MAP.red.second] = temp;
        MAP.red = make_pair(rx, ry);
        moveRB.first = true;
        break;
      }
    }

    bx = MAP.blue.first+dx; by = MAP.blue.second+dy;
    //blue
    switch(MAP.map[bx][by]) {
      case '#':
      case 'R': {
        moveRB.second = false;
        break;
      }
      case 'O': {
        return make_pair(holeRB.first, true);
      }
      case '.': {
        char temp = MAP.map[bx][by];
        MAP.map[bx][by] = MAP.map[MAP.blue.first][MAP.blue.second];
        MAP.map[MAP.blue.first][MAP.blue.second] = temp;
        MAP.blue = make_pair(bx, by);
        moveRB.second = true;
        break;
      }
    }
  }
  return holeRB;
}

// pair <red hole, blue hole>
pbb moveBalls(MAP_ &MAP, int dir) {
  int dx=0, dy=0;
  switch(dir) {
    case 0: {//UP
      dx = -1; dy = 0;
      break;
    }
    case 1: {//RIGHT
      dx = 0; dy = 1;
      break;
    }
    case 2: {//DOWN
      dx = 1; dy = 0;
      break;
    }
    case 3: {//LEFT
      dx = 0; dy = -1;
      break;
    }
  }
  return moveURDL(MAP, dx, dy);
}

int simulate(MAP_ MAP, vi &dirSet, int i) {
  int cnt = 0;
  pii red = MAP.red;
  pii blue = MAP.blue;
  pbb holeRB;

  for (int dir : dirSet) {
    red = MAP.red;
    blue = MAP.blue;

    holeRB = moveBalls(MAP, dir);
    
    cnt++;

    if (holeRB.second) return -1;//파란공이 구멍에 빠짐
    if (holeRB.first) return cnt;

    if (red == MAP.red && blue == MAP.blue) return -1; //의미 없는 움직임
  }

  return -1;
}

void solution() {
  MAP_ MAP;
  vi dirSet;

  init(MAP);

  int cnt = -1, temp;
  const int maxDir = (1<<20) - 1;

  for (int i = 0; i < maxDir; i++) {
    dirSet = makeDirSet(i);

    if (!isValidDirSet(dirSet))
      continue;
    
    temp = simulate(MAP, dirSet, i);
    
    if (temp == -1) 
      continue;
    
    if (cnt == -1 || cnt > temp)
      cnt = temp;
  }
  printf("%d\n", cnt);
}

int main(void) {
  solution();
  return 0;
}