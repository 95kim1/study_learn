//[boj 1874 : 스택 수열](https://www.acmicpc.net/problem/1874)

#include <iostream>
#include <stack>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::stack<int> s;
    std::string str;
    
    int m = 1; // stack에 push 되어야 하는 수
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        
        if (m <= num) {
            for (int j = m; j <= num; j++) {
                s.push(j);
                str+="+\n";
            }
            s.pop();
            str+="-\n";
            
            m = num+1;
        }
        else if (s.top() == num){
            s.pop();
            str+="-\n";
        }
        else {
            str = "NO\n";
            break;
        }
    }
    
    std::cout << str;
    
    return 0;
}
