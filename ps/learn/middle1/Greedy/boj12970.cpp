#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
  int n, k;
  cin >> n >> k;
  vector<int> A;
  for (int a = 1; a < n; a++)
  { // A: a개, B: b개
    int b = n - a;
    if (a * b < k)
      continue;

    //A[i] 는  0  1  2  ...   i   ...   a
    //          A  A  A ... A  A ...  A  :  a개
    // i 위치에 들어갈 B의 개수  A[i]++  =>  AB쌍 개수 += i
    A.resize(a + 1);
    for (int &elem : A)
      elem = 0;

    for (int i = 1; i <= b; i++)
    { //b개 만큼 B를 채우기
      int pos = (k <= a) ? k : a;
      A[pos]++;
      k -= pos;
    }

    string str = "";
    for (int i = 0; i <= a; i++)
    {
      while (A[i] > 0)
      {
        A[i]--;
        str += "B";
      }
      str += "A";
    }
    str.pop_back();

    cout << str << '\n';

    return 0;
  }
  cout << "-1\n";
  return 0;
}