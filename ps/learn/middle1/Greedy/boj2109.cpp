#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#define MAXDAY 10000
using namespace std;
using pii = pair<int,int>;
using iter = multiset<int>::iterator;

int solution(int n, vector<pii> request) {//pii : p,d
	int answer = 0;
	multiset<int> day;
	
	for (int d = 1; d <= MAXDAY; d++) {
		day.insert(d);
	}
	
	sort(request.begin(), request.end(), [](pii &a, pii &b)->bool {
		if (a.first < b.first)
			return true;
		return false;
	});
	
	while(!request.empty()) {
		int p = request.back().first;
		int d = request.back().second;
		request.pop_back();
		
		iter it = day.lower_bound(d);

    if (it != day.end() && *it == d) {
      day.erase(it);
      answer += p;
    }
    else if (it != day.begin()) {
      it--;
      day.erase(it);
      answer += p;
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
	for (int p,d,i=0; i<n; i++) {
		cin >> p >> d;
		request.push_back({p,d});
	}
	cout << solution(n,request) << '\n';
	return 0;
}