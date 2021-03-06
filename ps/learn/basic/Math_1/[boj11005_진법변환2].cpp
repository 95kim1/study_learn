//[boj 11005 : 진법 변환 2](https://www.acmicpc.net/problem/11005)

#include <iostream>
#include <vector>
#include <string>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, b, temp;
    std::cin >> n >> b;
    
    std::string ans;
    while(n) {
        temp = n%b;
        ans += (temp >= 10)?(char)(temp+55):(char)(temp+'0');
        n/=b;
    }
    
    int s = 0, e = (int)ans.length()-1;
    while(s < e) {
        temp = ans[s];
        ans[s++] = ans[e];
        ans[e--] = temp;
    }
    
    std::cout << ans << '\n';
    
    return 0;
}
