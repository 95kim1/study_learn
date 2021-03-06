//[boj 1373 : 2진수 8진수](https://www.acmicpc.net/problem/1373)

#include <iostream>
#include <stack>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::stack<char> s;
    std::string str, ans;
    std::cin >> str;
    
    int n = 0, cnt = 0;
    for (int i = (int)str.length()-1; i >= 0; i--) {
        if (cnt == 3) {
            ans += std::to_string(n);
            n = 0;
            cnt = 0;
        }
        n += (str[i]-'0') * (1<<cnt);
        cnt++;
    }
    
    if (n || ans.length()==0)
        ans += (char)(n+'0');
    
    int st = 0, e = (int)ans.length()-1, temp;
    while(st < e) {
        temp = ans[st];
        ans[st++] = ans[e];
        ans[e--] = temp;
    }
    
    std::cout << ans << '\n';
    
    return 0;
}
