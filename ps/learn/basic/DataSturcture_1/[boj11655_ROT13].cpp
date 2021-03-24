//[boj 11655 : ROT13](https://www.acmicpc.net/problem/11655)

#include <iostream>
#include <string>
using namespace std;
int cnt[4];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str, ans;
    getline(cin, str);
    
    for (char c : str) {
        if ('a' <= c && c <= 'z') {
            ans += ((c-'a') + 13)%26 + 'a';
        }
        else if ('A' <= c && c <= 'Z') {
            ans += ((c-'A') + 13)%26 + 'A';
        }
        else {
            ans += c;
        }
    }
    cout << ans << '\n';
    return 0;
}

