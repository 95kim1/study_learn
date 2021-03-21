[boj 10845 : 큐](https://www.acmicpc.net/problem/10845)

```c
#include <iostream>

class node_ {
    int data;
    node_ *next_;
public:
    node_(){next_ = nullptr;}
    node_(int d): data(d) {next_ = nullptr;}
    
    int getData() {
        return data;
    }
    node_* getNext() {
        return next_;
    }
    
    void setData(int d) {
        data = d;
    }
    void setNext(node_ *n) {
        next_ = n;
    }
};

class queue_int {
    int size_;
    node_ *head;
    node_ *tail;
public:
    queue_int() {
        size_ = 0;
        head = tail = nullptr;
    }
    ~queue_int() {
        while (!empty()) {
            pop();
        }
    }
    
    void push(int data) {
        node_ *temp = new node_(data);

        if (size_ == 0) {
            head = tail = temp;        }
        else {
            tail->setNext(temp);
            tail = temp;
        }
        size_++;
    }
    
    int pop() {
        if (size_ == 0) {
            return -1;
        }
        
        node_ *temp = head;
        head = head->getNext();
        
        if (head == nullptr) tail = nullptr;
        
        int data = temp->getData();
        delete temp;
        size_--;
        return data;
    }
    
    int size__() {
        return size_;
    }
    
    int empty() {
        if (size_) return 0;
        return 1;
    }
    
    int front() {
        if (empty()) return -1;
        return head->getData();
    }
    
    int back() {
        if (empty()) return -1;
        return tail->getData();
    }
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    queue_int qint;
    while(n--) {
        char s[6];
        std::cin >> s;
        if (s[0] == 'p') {
            if (s[1] == 'u') {
                int d;
                std::cin >> d;
                qint.push(d);
            }
            else if (s[1] == 'o') {
                std::cout << qint.pop() << '\n';
            }
        }
        else if (s[0] == 's') {
            std::cout << qint.size__() << '\n';
        }
        else if (s[0] == 'e') {
            std::cout << qint.empty() << '\n';
        }
        else if (s[0] == 'b') {
            std::cout << qint.back() << '\n';
        }
        else if (s[0] == 'f') {
            std::cout << qint.front() << '\n';
        }
        
    }
    return 0;
}
```
