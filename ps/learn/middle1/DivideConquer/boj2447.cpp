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

void fillBlanks(vector<string> &cur_star, int row, int size, int len)
{
  string blanks;
  for (int i = 0; i < len; i++)
    blanks += " ";
  for (int i = 0; i < size; i++)
    cur_star[row + i] += blanks;
}

vector<string> getStars(int N)
{
  if (N == 1)
    return {"*"};

  vector<string> prev_star = getStars(N / 3);
  vector<string> cur_star = vector<string>(prev_star.size() * 3);

  fillStars(cur_star, 0, prev_star);
  fillStars(cur_star, 0, prev_star);
  fillStars(cur_star, 0, prev_star);

  int size = (int)prev_star.size();

  fillStars(cur_star, size, prev_star);
  fillBlanks(cur_star, size, size, (int)prev_star[0].length());
  fillStars(cur_star, size, prev_star);

  size += size;

  fillStars(cur_star, size, prev_star);
  fillStars(cur_star, size, prev_star);
  fillStars(cur_star, size, prev_star);

  return cur_star;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  vector<string> stars = getStars(n);
  for (string &s : stars)
  {
    for (char &c : s)
      std::cout << c;
    std::cout << '\n';
  }
  return 0;
}