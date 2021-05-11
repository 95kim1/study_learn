#include <iostream>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	if (n==2) {
		if (m < 7)
			cout << (m+1)/2 << '\n';
		else
			cout << "4\n";
		return 0;	
	}
	
	if (m <= 4)
		cout << m << "\n";
	else if (m <= 6)
		cout << "4\n";
	else {
		cout << 5 + (m-7) << '\n';
	}

	return 0;
}