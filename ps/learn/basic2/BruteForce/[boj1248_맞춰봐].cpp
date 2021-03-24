//[boj 1248 : 맞춰봐](https://www.acmicpc.net/problem/1248)

#include <iostream>
#include <string>
#include <vector>

bool check(std::vector<std::vector<int> > &S, std::vector<int> &ans, int &idx) {
    int sum = 0;
    for (int i = idx; i >= 0; i--) {
        sum += ans[i];
        if (sum >= 0 && S[i][idx] < 0) {
            return false;
        } else if (sum <= 0 && S[i][idx] > 0) {
            return false;
        } else if (sum != 0 && S[i][idx] == 0){
            return false;
        }
    }
    return true;
}

bool findA(std::vector<std::vector<int> > &S, int &n, std::vector<int> &ans, int idx, bool &stop_flag) {
    if (stop_flag) return true;
    
    if (idx == n) {
        stop_flag = true;
        return true;
    }
    
    if (S[idx][idx] == 0) {
        ans[idx] = 0;
        return check(S,ans,idx) && findA(S,n,ans,idx+1, stop_flag);
    }
    
    for (int i = 1; i <= 10; i++) {
        ans[idx] = S[idx][idx] * i;
        if (check(S,ans,idx) && findA(S,n,ans,idx+1, stop_flag))
            return true;
    }
    
    return false;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > S(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            S[i].push_back(0);
        }
        for (int j = i; j < n; j++) {
            char c;
            std::cin >> c;
            if (c=='+')
                S[i].push_back(1);
            else if (c=='-')
                S[i].push_back(-1);
            else
                S[i].push_back(0);
        }
    }
    
    std::vector<int> ans(n);
    bool stop_flag = false;
    findA(S, n, ans, 0, stop_flag);
    
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
