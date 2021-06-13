#include <iostream>
#include <vector>
#include <algorithm>

#define vector std::vector
#define pair std::pair

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  vector<pair<int, int>> coords(n);
  for (pair<int, int> &elem : coords)
    std::cin >> elem.first >> elem.second;

  std::sort(coords.begin(), coords.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool
            {
              if (a.second < b.second)
                return true;
              else if (a.second == b.second && a.first < b.first)
                return true;
              return false;
            });

  for (pair<int, int> &elem : coords)
    std::cout << elem.first << ' ' << elem.second << '\n';

  return 0;
}