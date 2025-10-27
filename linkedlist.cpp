#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertFront(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }

    void remove(int x) {
        if (!head) return;
        if (head->val == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->val != x)
            curr = curr->next;
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.print();
    list.remove(10);
    list.print();
}
