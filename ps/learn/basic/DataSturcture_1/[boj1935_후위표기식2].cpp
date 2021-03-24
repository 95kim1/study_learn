//[boj 1935 : 후위 표기식2](https://www.acmicpc.net/problem/1935)

#include <iostream>
#include <string>
#include <vector>
#include <stack>

double cal(std::string &str, std::vector<int> &v) {
    std::stack<double> s;
    
    // A:65, Z:90
    for (char c : str) {
        if ('A' <= c && c <= 'Z') {
            s.push((double)v[(int)(c-'A')]);
        }
        else {
            double temp = s.top();
            s.pop();
            switch(c) {
                case '+':
                    temp = s.top() + temp;
                    break;
                case '-':
                    temp = s.top() - temp;
                    break;
                case '*':
                    temp = s.top() * temp;
                    break;
                case '/':
                    temp = s.top() / temp;
                    break;
            }
            s.pop();
            s.push(temp);
        }
    }
    
    return s.top();
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    
    int n;
    std::cin >> n >> str;
    
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    
    printf("%.2f\n", cal(str, v));
    
    return 0;
}

