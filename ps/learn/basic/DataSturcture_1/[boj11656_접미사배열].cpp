//[boj 11656 : 접미사 배열](https://www.acmicpc.net/problem/11656)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;
    
    std::vector<std::string> v;
    
    while(!str.empty()) {
        v.push_back(str);
        str.erase(0,1);
    }
    
    std::sort(v.begin(), v.end());
    
    for (std::string s : v)
        std::cout << s << '\n';
    
    return 0;
}
