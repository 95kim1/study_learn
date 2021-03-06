//[boj 10820 : 문자열 분석](https://www.acmicpc.net/problem/10820)

 #include <iostream>
#include <string>
using namespace std;
int cnt[4];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    
    while(getline(cin, str)) {
        for (char c : str) {
            if ('a' <= c && c <= 'z')
                cnt[0]++;
            else if ('A' <= c && c <= 'Z')
                cnt[1]++;
            else if ('0' <= c && c <= '9')
                cnt[2]++;
            else
                cnt[3]++;
        }
    
        for (int i = 0; i < 4; i++) {
            cout << cnt[i] << ' ';
            cnt[i] = 0;
        }
        cout << '\n';
    }
    
    
    
    return 0;
}
 
