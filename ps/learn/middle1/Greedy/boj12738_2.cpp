#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> ary(n);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}
	
	vector<int> length; 
  //length[i] : 길이가 (i+1)인 부분수열 중 가장 마지막 값.  
  //(이 마지막 값이 작을 수록 최대 길이를 만드는 데에 유리하다)
  //(즉 원 수열(ary)을 순서대로 탐색하면서 현재 탐색하고 있는 수를 다른 수열(length)에 삽입한다. 이 때 삽입 위치는 이분탐색으로 찾는다.)
  //ex -> ary = {5,6,7,1,2}
  //  length : 5, {} -> 6, {5} -> 7, {5,6} -> 1, {5,6,7} -> 2, {1,6,7} -> x, {1,2,7}
  //  마지막에 나온 수열 {1,2,7}의 의미는 '길이 1인 수열의 마지막 수는 1, 길이 2: 마지막 수 2, 길이 3: 마지막 수 7' 이다.
	for (int i = 0; i < n; i++) {
		int data = ary[i];
		vector<int>::iterator it = lower_bound(length.begin(), length.end(), data);
    if (it == length.end()) {
      length.push_back(data);
    }
    else {
      *it = data;
    }
	}
	cout << (int)length.size() << '\n';
	return 0;
}