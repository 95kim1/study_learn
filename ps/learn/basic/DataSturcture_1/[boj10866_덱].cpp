//[boj 10866 : 덱](https://www.acmicpc.net/problem/10866)

#include <iostream>
#include <string>

class node {
    int data;
    node *next;
    node *prev;
public:
    node(int d = 0): data(d) {
        prev = next = nullptr;
    }
    
    int getData() {
        return data;
    }
    node* getNext() {
        return next;
    }
    node* getPrev() {
        return prev;
    }
    
    void setData(int d) {
        data = d;
    }
    void setNext(node* n) {
        next = n;
    }
    void setPrev(node* p) {
        prev = p;
    }
};

class deque_int {
    int size;
    node*head;
    node*tail;
public:
    deque_int() {
        size = 0;
        head = tail = nullptr;
    }
    ~deque_int() {
        while(head!=nullptr) {
            pop_front();
        }
    }
    
    void push_front(int data) {
        node *temp = new node(data);
        if (size == 0) {
            head = tail = temp;
        }
        else {
            temp->setNext(head);
            head->setPrev(temp);
            head = temp;
        }
        size++;
    }
    void push_back(int data) {
        node *temp = new node(data);
        if (size == 0) {
            head = tail = temp;
        }
        else {
            temp->setPrev(tail);
            tail->setNext(temp);
            tail = temp;
        }
        size++;
    }
    
    int pop_front() {
        if (size == 0) return -1;
        int data = head->getData();
        node*temp = head;
        head = head->getNext();
        if (head == nullptr) tail = nullptr;
        else head->setPrev(nullptr);
        delete temp;
        size--;
        return data;
        
    }
    int pop_back() {
        if (size==0) return -1;
        int data = tail->getData();
        node*temp = tail;
        tail = tail->getPrev();
        if (tail == nullptr) head = nullptr;
        else tail->setNext(nullptr);
        delete temp;
        size--;
        return data;
    }
    
    int size_() {
        return size;
    }
    
    int empty() {
        if (size) return 0;
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
    std::string s;
    deque_int q;
    while(n--) {
        std::cin >> s;
        if (s[0] == 'p') {
            if (s[1] == 'u') {
                int d;
                std::cin >> d;
                if (s[5] == 'b')
                    q.push_back(d);
                else
                    q.push_front(d);
            }
            else {
                if (s[4] == 'b')
                    std::cout << q.pop_back() << '\n';
                else
                    std::cout << q.pop_front() << '\n';
            }
        }
        else if (s[0] == 's') {
            std::cout << q.size_() << '\n';
        }
        else if (s[0] == 'e') {
            std::cout << q.empty() << '\n';
        }
        else if (s[0] == 'f') {
            std::cout << q.front() << '\n';
        }
        else if (s[0] == 'b') {
            std::cout << q.back() << '\n';
        }
    }
    return 0;
}

