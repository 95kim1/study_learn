#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, std::string>> list(n);
  for (std::pair<int, std::string> &elem : list)
    std::cin >> elem.first >> elem.second;

  std::stable_sort(list.begin(), list.end(), [](const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) -> bool
                   {
                     if (a.first < b.first)
                       return true;
                     return false;
                   });

  for (std::pair<int, std::string> &elem : list)
    std::cout << elem.first << ' ' << elem.second << '\n';

  return 0;
}