#include <iostream>

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  int count_arr[10001] = {
      0,
  };
  int n;
  std::cin >> n;
  for (int temp, i = 0; i < n; i++)
  {
    std::cin >> temp;
    count_arr[temp]++;
  }

  for (int i = 1; i <= 10000; i++)
  {
    for (int j = 0; j < count_arr[i]; j++)
    {
      std::cout << i << '\n';
    }
  }

  return 0;
}
