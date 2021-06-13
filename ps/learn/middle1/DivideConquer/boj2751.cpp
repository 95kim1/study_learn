#include <iostream>
#include <vector>
#include <cmath>

#define vector std::vector

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int partition(int s, int e, vector<int> &arr)
{
  int mid = (s + e) / 2;
  int pivotElem = arr[mid];

  int storeIdx = s;
  int compIdx = s;

  swap(arr[mid], arr[e]);

  while (compIdx < e)
  {
    if (arr[compIdx] < pivotElem)
      swap(arr[storeIdx++], arr[compIdx]);

    compIdx++;
  }

  swap(arr[storeIdx], arr[e]);

  return storeIdx;
}

void mergeSort(int s, int e, vector<int> &arr)
{
  if (s >= e)
    return;

  int mid = (s + e) / 2;
  mergeSort(s, mid, arr);
  mergeSort(mid + 1, e, arr);

  int left = s;
  int right = mid + 1;

  vector<int> temp;
  while (left <= mid && right <= e)
  {
    if (arr[left] < arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]);
  }
  while (left <= mid)
    temp.push_back(arr[left++]);
  while (right <= e)
    temp.push_back(arr[right++]);

  for (int i = s; i <= e; i++)
    arr[i] = temp[i - s];
}

void mySort(int s, int e, vector<int> &arr, int depth, int n)
{
  if (depth == n)
  {
    mergeSort(s, e, arr);
    return;
  }

  if (s >= e)
    return;

  int pivot = partition(s, e, arr);

  mySort(s, pivot - 1, arr, depth + 1, n);
  mySort(pivot + 1, e, arr, depth + 1, n);
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);

  int n;

  std::cin >> n;
  vector<int> arr(n);
  for (int &elem : arr)
    std::cin >> elem;

  mySort(0, n - 1, arr, 0, 3 * std::log(n));

  for (int &elem : arr)
    std::cout << elem << '\n';

  return 0;
}