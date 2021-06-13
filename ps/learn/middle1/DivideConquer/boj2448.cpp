#include <iostream>
#include <vector>
#include <string>
#define vector std::vector
#define string std::string

void fillStars(vector<string> &cur_star, int row, vector<string> &prev_star)
{
  int vtr_len = (int)prev_star.size();
  for (int i = 0; i < vtr_len; i++)
  {
    cur_star[row + i] += prev_star[i];
  }
}

void fillBlanks(vector<string> &cur_star, int row, vector<string> &prev_star)
{
  int len = (int)prev_star.size();
  int blankCnt = (int)prev_star[len - 1].length();
  string s;
  for (int i = 0; i < blankCnt; i++)
    s += " ";

  for (int i = 0; i < len; i++)
  {
    cur_star[row + i] += s;
    s.pop_back();
    s.pop_back();
  }
}

vector<string> getStars(int N)
{
  if (N == 3)
    return {"*", "* *", "*****"};

  vector<string> prev_star = getStars(N / 2);
  vector<string> cur_star = vector<string>(prev_star.size() * 2);

  fillStars(cur_star, 0, prev_star);

  int size = (int)prev_star.size();

  fillStars(cur_star, size, prev_star);
  fillBlanks(cur_star, size, prev_star);
  fillStars(cur_star, size, prev_star);

  return cur_star;
}

void printStars(vector<string> &star)
{
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  int blankCnt = (int)star.size();

  string blank;
  for (int i = 0; i < blankCnt - 1; i++)
    blank += " ";

  for (string &s : star)
  {
    std::cout << blank << s << blank << '\n';
    blank.pop_back();
  }
}

int main(void)
{
  int n;
  std::cin >> n;
  vector<string> stars = getStars(n);
  printStars(stars);
  return 0;
}