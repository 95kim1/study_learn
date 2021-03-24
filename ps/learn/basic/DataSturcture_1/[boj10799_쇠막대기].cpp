//[boj 10799 : 쇠막대기](https://www.acmicpc.net/problem/10799)

#include <iostream>
#include <stack>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    
    std::stack<char> s;
    bool laser = false;
    int cnt = 0;
    for (char c : str) {
        switch(c) {
            case '(':
                s.push(c);
                laser = true;
                break;
            case ')':
                s.pop();
                
                cnt += (laser) ? (int)s.size() : 1;
                
                laser = false;
                break;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}

