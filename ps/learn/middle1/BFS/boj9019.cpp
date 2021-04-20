#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int changeNumStr(int i, int num) {
  switch(i) {
  case 0://cmd D
    num = 2*num % 10000;
    break;
  case 1://cmd S
    num = (num == 0) ? 9999 : num-1;
    break;
  case 2://cmd L
    num = (num % 1000)*10 + (num / 1000);
    break;
  case 3://cmd R
    num = (num/10) + 1000*(num%10);
    break;
  }
  return num;
}

string solution(int start, int end) {
  string answer = "";
  int num, nextNum;//현재/다음 숫자
  vector<int> path(10000, -2);//숫자(idx)가 어떤 숫자로부터 변경됐는지
  vector<int> cmdPath(10000, -2);//숫자(idx)가 어떤 명령어로 인해 변경된 결과인지
  queue<int> q;
  
  num = start;
  q.push(num);
  path[num] = cmdPath[num] = -1;
  
  while(!q.empty()) {
    num = q.front();
    q.pop();

    if (num == end) {
      break;
    }

    for (int i = 0; i < 4; i++) {//i: 0123 => DSLR
      nextNum = changeNumStr(i, num);
      
      if (path[nextNum] != -2)// 이미 구한 숫자는 pass
        continue;
      
      path[nextNum] = num;
      cmdPath[nextNum] = i;
      q.push(nextNum);
    }
  }

  char cmd[4] = {'D', 'S', 'L', 'R'};
  while(end != start) {
    answer += cmd[cmdPath[end]];
    end = path[end];
  }

  int s = 0, e = (int)answer.length()-1;
  while(s < e) {
    char c = answer[s];
    answer[s] = answer[e];
    answer[e] = c;
    s++; e--;
  }

  return answer;
}

int main(void) {
  int t;
  int start, end;
  cin >> t;
  while(t--) {
    cin >> start >> end;
    cout << solution(start, end) << '\n';
  }
  return 0;
}