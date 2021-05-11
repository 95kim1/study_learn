#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
using pii = pair<int,int>;
using iter = multiset<int>::iterator;

int solution(int n, int d, vector<pii> request) {//pii : p,d
	int answer = 0;
	multiset<int> prices;
	for (int i = 1; i <= d; i++) {
		request.push_back({-1,i});
	}

	sort(request.begin(), request.end(), [](pii&a,pii&b)->bool{
		if (a.second < b.second)
			return true;
		if (a.second == b.second && a.first < b.first)
			return true;
		return false;
	});

	while(!request.empty()) {
		int p = request.back().first;
		int d = request.back().second;
		request.pop_back();

		if (p == -1 && !prices.empty()) {
			iter it = prices.end();
			it--;
			answer += *it;
			prices.erase(it);
		}
		else if (p != -1){
			prices.insert(p);
		}
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pii> request;
	int maxD = 0;
	for (int p,d,i=0; i<n; i++) {
		cin >> p >> d;
		if (d > maxD) {
			maxD = d;
		}
		request.push_back({p,d});
	}
	cout << solution(n,maxD,request) << '\n';
	return 0;
}