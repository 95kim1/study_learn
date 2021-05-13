#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool bSearch(int data, vector<int> &ary)
{
  int s = 0, e = (int)ary.size() - 1, mid;
  do
  {
    mid = (s + e) / 2;
    if (ary[mid] < data)
      s = mid + 1;
    else if (data < ary[mid])
      e = mid - 1;
    else
      return true;
  } while (s <= e);
  return false;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cards[i];
  }
  sort(cards.begin(), cards.end());

  cin >> m;
  vector<int> myNums(m);
  for (int i = 0; i < m; i++)
  {
    cin >> myNums[i];
  }

  for (int i = 0; i < m; i++)
  {
    if (bSearch(myNums[i], cards))
      cout << "1 ";
    else
      cout << "0 ";
  }
  cout << '\n';

  return 0;
}