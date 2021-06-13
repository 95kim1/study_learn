#include <iostream>
#include <algorithm>
#include <vector>
#define vector std::vector

long long merge(vector<int> &arr, int start, int mid, int end)
{
  int i = start, j = mid + 1;
  long long answer = 0;

  vector<int> arr_temp;

  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      arr_temp.push_back(arr[i++]);
    }
    else
    {
      answer += mid - i + 1;
      arr_temp.push_back(arr[j++]);
    }
  }
  while (i <= mid)
    arr_temp.push_back(arr[i++]);

  while (j <= end)
    arr_temp.push_back(arr[j++]);

  for (int i = end; i >= start; i--)
  {
    arr[i] = arr_temp.back();
    arr_temp.pop_back();
  }
  return answer;
}

long long sortBinary(vector<int> &arr, int start, int end)
{
  if (start >= end)
    return 0;
  int mid = (start + end) / 2;
  long long answer = 0;
  answer += sortBinary(arr, start, mid);
  answer += sortBinary(arr, mid + 1, end);

  answer += merge(arr, start, mid, end);

  return answer;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
  long long answer = sortBinary(arr, 0, n - 1);
  std::cout << answer << '\n';
  return 0;
}