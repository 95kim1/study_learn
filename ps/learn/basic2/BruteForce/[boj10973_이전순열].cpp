//[boj 10973 : 이전 순열](https://www.acmicpc.net/problem/10973)

#include <iostream>
#include <vector>

/* a > b : true */
template<class T>
bool nextPermutation(std::vector<T> &v, bool (*comp)(T a, T b)=[](T a, T b)->bool{return (a>b) ? true : false;}) {
    bool last = true;
    int i, j = (int)v.size();
    for (i = (int)v.size()-1; i > 0; i--) {
        if (comp(v[i], v[i-1])) {
            last = false;
            break;
        }
    }
    
    // 654321 같은 경우 : 마지막 패턴임. ->
    if (last) {
        return !last;
    }
    
    for (j = i; j < (int)v.size(); j++) {
        if (!comp(v[j], v[i-1])) {
            break;
        }
    }
    j--;
    
    // check that "deep copy operator=" is operating well
    T temp = v[j];
    v[j] = v[i-1];
    v[i-1] = temp;

    j = (int)v.size()-1;
    while(i < j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++; j--;
    }
    return !last;
}

// a > b : true
template<class T>
bool prevPermutation(std::vector<T> &v, bool (*comp)(T a, T b)=[](T a, T b)->bool{return (a>b) ? true : false;}) {
    bool first = true;
    int i, j = (int)v.size();
    for (i = (int)v.size()-1; i > 0; i--) {
        if (comp(v[i-1], v[i])) {
            first = false;
            break;
        }
    }
    
    if (first) {
        return !first;
    }
    
    for (j = i; j < (int)v.size(); j++) {
        if (!comp(v[i-1], v[j])) {
            break;
        }
    }
    j--;
    
    T temp = v[i-1];
    v[i-1] = v[j];
    v[j] = temp;
    
    j = (int)v.size()-1;
    while(i < j) {
        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++; j--;
    }
    return !first;
}

void printAll(std::vector<int> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    
    if (prevPermutation(v)) {
        printAll(v);
    }
    else {
        printf("-1\n");
    }
    
    return 0;
}
