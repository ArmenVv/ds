#include <iostream>
using namespace std;

struct Node {
    int val;
    int priority;
    Node* next;
    Node(int v, int p) : val(v), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head; 
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int val, int priority) {
        Node* n = new Node(val, priority);
        if (!head || priority > head->priority) {
            n->next = head;
            head = n;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->priority >= priority) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        return head ? head->val : -1;
    }

    bool empty() {
        return head == nullptr;
    }

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(15, 3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.dequeue();
    }
    cout << "\n"; 
}
