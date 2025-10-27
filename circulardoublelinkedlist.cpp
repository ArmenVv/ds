#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class CircularDoubleLinkedList {
private:
    Node* tail;
public:
    CircularDoubleLinkedList() : tail(nullptr) {}

    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
            return;
        }
        Node* head = tail->next;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
            return;
        }
        Node* head = tail->next;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
    }

    void remove(int x) {
        if (!tail) return;
        Node* curr = tail->next;
        Node* head = tail->next;
        while (true) {
            if (curr->val == x) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = nullptr;
                    return;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == tail)
                    tail = curr->prev;
                delete curr;
                return;
            }
            curr = curr->next;
            if (curr == head) break;
        }
    }

    void printForward() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* curr = tail->next;
        Node* head = tail->next;
        while (true) {
            cout << curr->val << " ";
            curr = curr->next;
            if (curr == head) break;
        }
        cout << "\n";
    }

    void printBackward() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* curr = tail;
        Node* start = tail;
        while (true) {
            cout << curr->val << " ";
            curr = curr->prev;
            if (curr == start) break;
        }
        cout << "\n";
    }

    ~CircularDoubleLinkedList() {
        if (!tail) return;
        Node* head = tail->next;
        Node* curr = head;
        while (curr != tail) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete tail;
    }
};

int main() {
    CircularDoubleLinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.printForward();   
    list.printBackward();  
    list.remove(10);
    list.printForward();   
    list.remove(5);
    list.remove(20);
    list.printForward();   
