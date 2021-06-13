#include <iostream>
#include <vector>
#include <algorithm>
#define vector std::vector

vector<vector<int>> init()
{
  int n;
  std::cin >> n;
  vector<vector<int>> buildings(n, vector<int>(3));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
      std::cin >> buildings[i][j];
  }
  std::sort(buildings.begin(), buildings.end(), [](vector<int> &left, vector<int> &right) -> bool
            { return left[0] < right[0]; });
  return buildings;
}

vector<vector<int>> findSkyline(int start, int end, vector<vector<int>> &buildings)
{
  if (start >= end)
  {
    return {{buildings[start][0], buildings[start][1]}, {buildings[end][2], 0}};
  }

  int mid = (start + end) / 2;
  vector<vector<int>> leftLine = findSkyline(start, mid, buildings);
  vector<vector<int>> rightLine = findSkyline(mid + 1, end, buildings);

  vector<vector<int>> skyline;

  int leftIdx = 0;
  int rightIdx = 0;
  int leftSize = (int)leftLine.size();
  int rightSize = (int)rightLine.size();

  int leftH = 0;
  int rightH = 0;
  while (leftIdx < leftSize && rightIdx < rightSize)
  {
    vector<int> leftPoint = leftLine[leftIdx];
    vector<int> rightPoint = rightLine[rightIdx];

    if (leftPoint[0] < rightPoint[0]) //x-coordinates comparison
    {
      if (rightH < leftPoint[1])
        skyline.push_back(leftPoint);
      else if (leftH > rightH)
        skyline.push_back({leftPoint[0], rightH});

      leftH = leftPoint[1];
      leftIdx++;
    }
    else if (leftPoint[0] == rightPoint[0])
    {
      int x = leftPoint[0];
      int y = (leftPoint[1] > rightPoint[1]) ? leftPoint[1] : rightPoint[1];
      int H = (leftH > rightH) ? leftH : rightH;

      if (H != y)
        skyline.push_back({x, y});

      leftH = leftPoint[1];
      rightH = rightPoint[1];
      leftIdx++;
      rightIdx++;
    }
    else
    {
      if (leftH < rightPoint[1])
        skyline.push_back(rightPoint);
      else if (rightH > leftH)
        skyline.push_back({rightPoint[0], leftH});

      rightH = rightPoint[1];
      rightIdx++;
    }
  }

  while (leftIdx < leftSize)
    skyline.push_back(leftLine[leftIdx++]);

  while (rightIdx < rightSize)
    skyline.push_back(rightLine[rightIdx++]);

  return skyline;
}

int main(void)
{
  vector<vector<int>> buildings = init();
  vector<vector<int>> skyline = findSkyline(0, (int)buildings.size() - 1, buildings);
  for (vector<int> &elem : skyline)
    std::cout << elem[0] << ' ' << elem[1] << ' ';
  std::cout << '\n';
  return 0;
}
