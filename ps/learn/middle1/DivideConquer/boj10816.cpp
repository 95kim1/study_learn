#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upperBound(int data, vector<int> &ary)
{
  int s = 0, e = (int)ary.size() - 1, mid;
  do
  {
    mid = (s + e) / 2;
    if (data == ary[mid])
      s = mid + 1;
    else if (data < ary[mid])
      e = mid - 1;
    else
      s = mid + 1;
  } while (s <= e);
  return e + 1;
}
int lowerBound(int data, vector<int> &ary)
{
  int s = 0, e = (int)ary.size() - 1, mid;
  do
  {
    mid = (s + e) / 2;

    if (data == ary[mid])
      e = mid - 1;
    else if (data < ary[mid])
      e = mid - 1;
    else
      s = mid + 1;
  } while (s <= e);
  return e + 1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n;
  vector<int> aryN(n);
  for (int &data : aryN)
    cin >> data;
  cin >> m;
  sort(aryN.begin(), aryN.end());
  vector<int> aryM(m);
  for (int &data : aryM)
    cin >> data;

  for (int data : aryM)
  {
    cout << upperBound(data, aryN) - lowerBound(data, aryN) << ' ';
  }
  cout << '\n';

  return 0;
}