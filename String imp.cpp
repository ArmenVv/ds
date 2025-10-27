#include <iostream>
using namespace std;

struct Node {
	char val;
	Node* next;

	Node(char x) {
		val = x;
		next = nullptr;
	}
};
class LinkedString {
public:
	LinkedString() : head(nullptr) {};
	LinkedString(const char* str) {
		if (str && *str) {
			head = new Node(*str);
			Node* current = head;
			++str;
			while (*str) {
				current->next = new Node(*str);
				current = current->next;
				++str;
			}
		}
	}
	~LinkedString() {
		Node* current = head;
		while (current) {
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
		head = nullptr;
	}
	void print() const{
		Node* current = head;
		while (current) {
			cout << current->val;
			current = current->next;
		}
		cout << '\n';
	}
	int length() {
		int len = 0;
		Node* current = head;
		while (current) {
			len++;
			current = current->next;
		}
		return len;
	}
	void resize(int newLen) {
		if (newLen < 0) return;
		int curLen = length();
		if (newLen == curLen) return;
		if (newLen < curLen) {
			if (newLen == 0) {
				Node* current = head;
				while (current) {
					Node* tmp = current;
					current = current->next;
					delete tmp;
				}
				head = nullptr;
				return;
			}
			Node* current = head;
			for (int i = 0; i < newLen - 1; i++) {
				current = current->next;
			}
			Node* toDelete = current->next;
			while (toDelete) {
				Node* tmp = toDelete;
				toDelete = toDelete->next;
				delete tmp;
			}
			current->next = nullptr;
		}
		else {
			if (!head) {
				head = new Node(' ');
				--newLen;
			}
			Node* current = head;
			while (current->next) {
				current = current->next;
			}
			for (int i = 0; i < newLen - curLen; i++) {
				current->next = new Node(' ');
				current = current->next;
			}
		}
	}
	int find(char ch) const {
		int index = 0;
		Node* current = head;
		while (current) {
			if (current->val == ch) return index;
		    ++index;
			current = current->next;

		}
		return -1;
	}
private:
	Node* head;
};
int main() {
	LinkedString s("hello");

	s.print(); 

	s.resize(8); 
	s.print();  

	s.resize(3); 
	s.print();   

	std::cout << "Index of 'e': " << s.find('e') << '\n';
	std::cout << "Index of 'z': " << s.find('z') << '\n'; 

	return 0;
}