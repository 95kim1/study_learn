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
  vector<pair<long long, int>> cards(n);
  for (pair<long long, int> &card : cards)
  {
    std::cin >> card.first;
    card.second = 1;
  }

  std::sort(cards.begin(), cards.end());

  for (int i = 1; i < n; i++)
  {
    pair<long long, int> &prev = cards[i - 1];
    pair<long long, int> &cur = cards[i];

    if (cur.first == prev.first)
      cur.second += prev.second;
  }

  int maxCnt = 0;
  long long card_maxCnt = 0;
  for (int i = 0; i < n; i++)
  {
    pair<long long, int> &cur = cards[i];
    if (maxCnt < cur.second)
    {
      maxCnt = cur.second;
      card_maxCnt = cur.first;
    }
  }

  std::cout << card_maxCnt << '\n';

  return 0;
}