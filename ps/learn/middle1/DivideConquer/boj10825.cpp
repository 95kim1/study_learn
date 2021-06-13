#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

#define vector std::vector
#define string std::string
#define tuple std::tuple

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;
  vector<tuple<string, int, int, int>> list(n);
  for (tuple<string, int, int, int> &elem : list)
  {
    string name;
    int kor;
    int eng;
    int math;
    tie(name, kor, eng, math) = elem;
    std::cin >> name >> kor >> eng >> math;
    elem = tie(name, kor, eng, math);
  }

  std::sort(list.begin(), list.end(), [](tuple<string, int, int, int> &a, tuple<string, int, int, int> &b) -> bool
            {
              string name_a, name_b;
              int kor_a, kor_b;
              int math_a, math_b;
              int eng_a, eng_b;
              tie(name_a, kor_a, eng_a, math_a) = a;
              tie(name_b, kor_b, eng_b, math_b) = b;

              if (kor_a > kor_b)
                return true;
              else if (kor_a == kor_b)
              {
                if (eng_a < eng_b)
                  return true;
                else if (eng_a == eng_b)
                {
                  if (math_a > math_b)
                    return true;
                  else if (math_a == math_b && name_a < name_b)
                    return true;
                }
              }
              return false;
            });

  for (tuple<string, int, int, int> &elem : list)
  {
    string name;
    int kor;
    int eng;
    int math;
    tie(name, kor, eng, math) = elem;
    std::cout << name << '\n';
  }

  return 0;
}