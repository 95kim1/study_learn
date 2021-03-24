//[boj 17298 : 오큰수](https://www.acmicpc.net/problem/17298)

#include <iostream>
#include <stack>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> A, NGE;
    for (int i = n; i > 0; i--) {
        std::cin >> n;
        A.push_back(n);
        NGE.push_back(-1);
    }
    
    std::stack<int> s;
    for (int i = 0; i < (int)A.size(); i++) {
        if (s.empty()) {
            s.push(i);
        }
        else {
            while(!s.empty() && A[s.top()] < A[i]) {
                NGE[s.top()] = A[i];
                s.pop();
            }
            s.push(i);
        }
    }
    
    std::cout << NGE[0];
    for (int i = 1; i < (int)A.size(); i++) {
        std::cout << ' ' << NGE[i];
    }
    std::cout << '\n';
    
    return 0;
}

