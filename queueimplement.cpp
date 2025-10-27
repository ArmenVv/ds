#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class Queue {
private:
    Node* head; 
    Node* tail; 
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int x) {
        Node* n = new Node(x);
        if (!tail) { 
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr; 
    }

    int front() {
        if (!head) return -1; 
        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }

    ~Queue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << "\n"; 
