#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
public:
    Deque() : head(nullptr), tail(nullptr) {}

    void pushFront(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void pushBack(int x) {
        Node* n = new Node(x);
        if (!tail) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void popFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void popBack() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    int front() {
        return head ? head->val : -1;
    }

    int back() {
        return tail ? tail->val : -1;
    }

    bool empty() {
        return head == nullptr;
    }

    ~Deque() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Deque dq;
    dq.pushBack(10);
    dq.pushFront(5);
    dq.pushBack(20);
    cout << dq.front() << " " << dq.back() << "\n"; 
    dq.popFront();
    dq.popBack();
    cout << dq.front() << " " << dq.back() << "\n"; 
}
