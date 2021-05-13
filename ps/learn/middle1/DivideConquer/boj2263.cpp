#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printPreOrderNodes(int sin, int ein, vector<int> &in, int spost, int epost, vector<int> &post, unordered_map<int, int> &umap)
{
  if (sin > ein)
    return;

  int parent = post[epost];
  int parentIdx_in = umap[parent];
  cout << parent << ' ';

  int parentIdx_post = epost - ein + parentIdx_in;

  printPreOrderNodes(sin, parentIdx_in - 1, in, spost, parentIdx_post - 1, post, umap);
  printPreOrderNodes(parentIdx_in + 1, ein, in, parentIdx_post, epost - 1, post, umap);
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> in(n), post(n);
  unordered_map<int, int> umap;
  for (int i = 0; i < n; i++)
  {
    cin >> in[i];
    umap[in[i]] = i;
  }
  for (int &node : post)
    cin >> node;
  printPreOrderNodes(0, n - 1, in, 0, n - 1, post, umap);
  cout << '\n';
  return 0;
}