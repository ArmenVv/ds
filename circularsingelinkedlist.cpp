#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int x) {
		val = x;
		next = nullptr;
	}
};
class CircularLinkedList {
public:
	CircularLinkedList() : tail(nullptr) {}
	void insert(int x) {
		Node* newNode = new Node(x);
		if (!tail) {
			tail = newNode;
			tail->next = tail;
		}
		else {
			newNode->next = tail->next;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void remove(int x) {
		if (!tail) return;
		Node* curr = tail->next;
		Node* prev = tail;
		
		while (true) {
			if (curr->val == x) {
				if (curr == tail && curr == tail->next) {
					delete curr;
					tail = nullptr;
				}
				else {
					prev->next = curr->next;
					if (curr == tail)
						tail = prev;
					delete curr;
				}
				return;
			}
			prev = curr;
			curr = curr->next;
			if (curr == tail->next) break;
		}
	}
	void print() {
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

	~CircularLinkedList() {
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
private:
	Node* tail;
};

int main() {
	CircularLinkedList list;
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.print(); 

	list.remove(20);
	list.print(); 

	list.remove(10);
	list.remove(30);
	list.print(); 
}
