#include <iostream>
#include <vector>
#include <algorithm>
#define vector std::vector
#define pair std::pair

vector<pair<int, int>> init()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); //...
  int n;
  std::cin >> n;
  vector<pair<int, int>> dots(n, pair<int, int>());
  for (pair<int, int> &dot : dots)
    std::cin >> dot.first >> dot.second;
  return dots;
}

bool cmpX(pair<int, int> &a, pair<int, int> &b)
{
  return a < b;
}

bool cmpY(pair<int, int> &a, pair<int, int> &b)
{
  return std::make_pair(a.second, a.first) < std::make_pair(b.second, b.first);
}

int square(int a)
{
  return a * a;
}

int dist(pair<int, int> &a, pair<int, int> &b)
{
  return square(a.first - b.first) + square(a.second - b.second);
}

int mindDist_bruteForce(int start, int end, vector<pair<int, int>> &dots)
{
  int min_dist = -1;
  int temp_dist;
  for (int i = start; i < end; i++)
  {
    for (int j = i + 1; j <= end; j++)
    {
      temp_dist = dist(dots[i], dots[j]);
      if (min_dist == -1 || min_dist > temp_dist)
        min_dist = temp_dist;
    }
  }
  return min_dist;
}

int findMinDist(int start, int end, vector<pair<int, int>> &dots)
{
  if (end - start < 3) // 1 or 2 or 3 vector<int> elements
  {
    return mindDist_bruteForce(start, end, dots);
  }

  int mid = (start + end) / 2;

  int dL = findMinDist(start, mid, dots);
  int dR = findMinDist(mid + 1, end, dots);
  int d = (dL > dR) ? dR : dL; // minimum distance from divide and conquer

  vector<pair<int, int>> temp_dots;
  for (int i = start; i <= end; i++)
  {
    // choose (a,b) such as x-d < a < x+d; a=dot[0], x=mid_dot[0].
    if (square(dots[i].first - dots[mid].first) < d)
      temp_dots.push_back(dots[i]);
  }

  std::sort(temp_dots.begin(), temp_dots.end(), cmpY);

  int len = (int)temp_dots.size();
  int temp_d;
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = i + 1; j < len; j++)
    {
      if (square(temp_dots[j].second - temp_dots[i].second) < d)
      {
        temp_d = dist(temp_dots[i], temp_dots[j]);
        if (temp_d < d)
          d = temp_d;
      }
      else
        break;
    }
  }

  return d;
}

int solution()
{
  vector<pair<int, int>> dots = init();
  std::sort(dots.begin(), dots.end(), cmpX); //sort by x-coordinate
  return findMinDist(0, (int)dots.size() - 1, dots);
}

int main(void)
{
  std::cout << solution() << '\n';
  return 0;
}