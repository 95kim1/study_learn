//[boj 17413 : 단어 뒤집기2](https://www.acmicpc.net/problem/17413)

#include <iostream>
#include <stack>
#include <string>
#include <chrono>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::getline(std::cin, str);
    
    std::stack<char> s;
    std::string ans;
    bool r_flag = true;
    
    for (char c : str) {
        r_flag = (c == '>') ? true : (c == '<') ? false : r_flag;
    
        if (r_flag) {
            if (c == ' ') {
                while(!s.empty()) {
                    ans+=s.top();
                    s.pop();
                }
                ans+=c;
            }
            else if (c != '>'){
                s.push(c);
            }
            else
                ans+=c;
        }
        else {
            while(!s.empty()) {
                ans+=s.top();
                s.pop();
            }
            ans+=c;
        }
    }
    while(!s.empty()) {
        ans+=s.top();
        s.pop();
    }
    
    std::cout << ans << '\n';
    
    return 0;
}

