//[boj 1212 : 8진수 2진수](https://www.acmicpc.net/problem/1212)

#include <iostream>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str, ans;
    std::cin >> str;
    
    for (int i = (int)str.length()-1; i >= 0; i--){
        int n = str[i]-'0';
        for (int j = 0; j < 3; j++) {
            ans += (char)(n%2 + '0');
            n/=2;
        }
    }
    
    int s = 0, e = (int)ans.length()-1, temp;
    
    while(ans[e]=='0') {
        e--;
    }
    ans = ans.substr(0,e+1);
    if (ans.empty())
        ans+='0';
    while(s < e) {
        temp = ans[s];
        ans[s++] = ans[e];
        ans[e--] = temp;
    }
    
    std::cout << ans << '\n';
    
    return 0;
}
