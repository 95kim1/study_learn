//[boj 9012 : 괄호](https://www.acmicpc.net/problem/9012)

#include <iostream>
#include <string>
#include <stack>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    while(n--) {
        std::string str;
        std::stack<char> s;
        std::cin >> str;
        bool tf = true;
        
        for(char ch : str) {
            if (ch == '(')
                s.push(ch);
            else {
                if (s.empty()) {
                    tf = false;
                    break;
                }
                s.pop();
            }
        }
        
        if (tf && s.empty()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    
    return 0;
}

