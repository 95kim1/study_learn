//[boj 1918 : 후위 표기식](https://www.acmicpc.net/problem/1918)
   
#include <iostream>
#include <stack>
#include <string>

int priority(char &c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 3;
    }
    return 0;
}

std::string postfix(std::string &str) {
    std::string ans;
    std::stack<char> s;
    
    for (char c : str) {
        if ('A' <= c && c <= 'Z') {
            ans+=c;
        }
        else if (c == ')') {
            while(s.top() != '(') {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if (c=='(' || s.empty() || priority(s.top()) < priority(c)) {
            s.push(c);
        }
        else {
            while(!s.empty() && s.top() != '(' && priority(s.top()) >= priority(c)) {
                ans+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()) {
        ans+=s.top();
        s.pop();
    }
    
    return ans;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;
    
    std::cout << postfix(str) << '\n';
    
    return 0;
}

