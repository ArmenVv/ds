#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int x) {
        Node* curr = head;
        while (curr) {
            if (curr->val == x) {
                if (curr == head && curr == tail) head = tail = nullptr;
                else if (curr == head) {
                    head = head->next;
                    head->prev = nullptr;
                }
                else if (curr == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void printForward() {
        Node* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void printBackward() {
        Node* curr = tail;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->prev;
        }
        cout << "\n";
    }

    ~DoubleLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoubleLinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.printForward();
    list.printBackward();
    list.remove(20);
    list.printForward();
}
