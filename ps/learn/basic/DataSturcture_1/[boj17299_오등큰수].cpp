//[boj 17299 : 오등큰수](https://www.acmicpc.net/problem/17299)
#include <iostream>
#include <stack>
#include <vector>
int freq[1000001];

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> A(n), NGE(n, -1);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
        freq[A[i]]++;
    }
    
    std::stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty())
            s.push(i);
        while(!s.empty() && freq[A[s.top()]] < freq[A[i]]) {
            NGE[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    
    std::cout << NGE[0];
    for (int i = 1; i < n; i++) {
        std::cout << ' ' << NGE[i];
    }
    std::cout << '\n';
    
    return 0;
}
