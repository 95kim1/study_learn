#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> A, B;
  int n, m;
  cin >> n >> m;
  A.resize(n);
  B.resize(m);
  for (int &a : A)
    cin >> a;
  for (int &b : B)
    cin >> b;

  vector<int> C;
  int i = 0, j = 0;
  while (i != n && j != m)
  {
    if (A[i] < B[j])
    {
      C.push_back(A[i++]);
    }
    else
    {
      C.push_back(B[j++]);
    }
  }
  while (i != n)
  {
    C.push_back(A[i++]);
  }
  while (j != m)
  {
    C.push_back(B[j++]);
  }

  for (int c : C)
  {
    cout << c << ' ';
  }
  cout << '\n';

  return 0;
}