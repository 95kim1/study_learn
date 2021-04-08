#include <iostream>
#include <utility>
#include <queue>

void writeEmoticon(int s) {
  int time[1001][1001];
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++)
      time[i][j] = -1;
  }

  std::queue<std::pair<int, int> > q;
  int screen = 1, clip = 0;
  q.push(std::make_pair(screen, clip));
  time[1][0] = 0;
  while(!q.empty()) {
    screen = q.front().first;
    clip = q.front().second;
    q.pop();

    if (screen == s)
      break;

    if (time[screen][screen] == -1) {
      q.push(std::make_pair(screen, screen));
      time[screen][screen] = time[screen][clip] + 1;
    }
    if (screen+clip<=1000 && time[screen+clip][clip] == -1) {
      q.push(std::make_pair(screen+clip, clip));
      time[screen+clip][clip] = time[screen][clip]+ 1;
    }
    if (screen > 0 && time[screen-1][clip] == -1) {
      q.push(std::make_pair(screen-1, clip));
      time[screen-1][clip] = time[screen][clip] + 1;
    }
  }

  printf("%d\n", time[s][clip]);
}


int main(void) {
  int s;
  std::cin >> s;
  writeEmoticon(s);
  return 0;
}