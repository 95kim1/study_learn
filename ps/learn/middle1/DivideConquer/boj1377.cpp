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
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i].first;
    arr[i].second = i;
  }

  std::sort(arr.begin(), arr.end());

  int max_diff = 0;
  for (int i = 0; i < n; i++)
  {
    if (max_diff < arr[i].second - i)
      max_diff = arr[i].second - i;
  }

  std::cout << max_diff + 1 << '\n';

  return 0;
}