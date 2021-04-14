#include <iostream>
#include <vector>
using namespace std;

int getEnergy(vector<int> &W, int depth, vector<bool> &choose, int sumW=0) {
  if (depth == (int)W.size()-2) {
    return sumW;
  }

  int Msum = 0;
  for (int i = 1; i < (int)W.size()-1; i++) {
    if (choose[i])
      continue;

    choose[i] = true;

    int idx = i+1;
    while(idx < (int)W.size() && choose[idx]) {
      idx++;
    }
    int W1 = W[idx]; //W[x-1]
    
    idx = i-1;
    while(idx >= 0 && choose[idx]) {
      idx--;
    }
    int W0 = W[idx]; //W[x+1]

    int temp = getEnergy(W, depth+1, choose, sumW + W0*W1);

    if (temp > Msum)
      Msum = temp;

    choose[i] = false; 
  }

  return Msum;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> W(n);
  vector<bool> choose(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
    choose[i] = false;
  }

  printf("%d\n", getEnergy(W, 0, choose));

  return 0;
}