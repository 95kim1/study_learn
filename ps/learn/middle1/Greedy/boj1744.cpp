#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &ary) {
	int answer = 0;
	for (int i = (int)ary.size()-1; i > 0; i-=2) {
			if (ary[i] + ary[i-1] < ary[i] * ary[i-1])
				answer += ary[i]*ary[i-1];
			else
				answer += ary[i]+ary[i-1];
	}
	if (ary.size()%2==1) {
		answer	 += ary[0];
	}
	return answer;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> positive, negative;
	for (int t, i = 0; i < n; i++) {
		cin >> t;
		if (t > 0)
			positive.push_back(t);
		else
			negative.push_back(t);
	}
	
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end(), [](int a, int b)->bool{
		return a > b;
	});
	
	int answer = solve(positive);
	answer += solve(negative);
	
	cout << answer << '\n';
	return 0;
}