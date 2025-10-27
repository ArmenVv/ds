#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;
public:
    Stack() : topNode(nullptr) {}

    void push(int x) {
        Node* n = new Node(x);
        n->next = topNode;
        topNode = n;
    }

    void pop() {
        if (!topNode) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (!topNode) return -1; 
        return topNode->val;
    }

    bool empty() {
        return topNode == nullptr;
    }

    ~Stack() {
        while (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n"; 
}
