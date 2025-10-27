#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
    Term* next;
    Term(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;
public:
    Polynomial() : head(nullptr) {}

    void insertTerm(int coeff, int exp) {
        if (coeff == 0) return;
        Term* newTerm = new Term(coeff, exp);

        if (!head || exp > head->exp) {
            newTerm->next = head;
            head = newTerm;
            return;
        }

        Term* curr = head;
        Term* prev = nullptr;

        while (curr && curr->exp > exp) {
            prev = curr;
            curr = curr->next;
        }

        if (curr && curr->exp == exp) {
            curr->coeff += coeff;
            if (curr->coeff == 0) {
                if (curr == head) {
                    head = head->next;
                    delete curr;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                }
            }
            delete newTerm;
        }
        else {
            newTerm->next = curr;
            prev->next = newTerm;
        }
    }

    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        Term* p1 = head;
        Term* p2 = other.head;

        while (p1 || p2) {
            if (!p2 || (p1 && p1->exp > p2->exp)) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            }
            else if (!p1 || (p2 && p2->exp > p1->exp)) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            }
            else {
                result.insertTerm(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    void print() const {
        if (!head) {
            cout << "0\n";
            return;
        }
        Term* curr = head;
        bool first = true;
        while (curr) {
            if (!first && curr->coeff > 0) cout << " + ";
            if (curr->coeff < 0) cout << " - ";
            cout << (first ? abs(curr->coeff) : abs(curr->coeff));
            if (curr->exp != 0) cout << "x";
            if (curr->exp > 1) cout << "^" << curr->exp;
            first = false;
            curr = curr->next;
        }
        cout << "\n";
    }

    ~Polynomial() {
        while (head) {
            Term* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Polynomial p1, p2;
    p1.insertTerm(5, 2);
    p1.insertTerm(3, 1);
    p1.insertTerm(2, 0);

    p2.insertTerm(2, 2);
    p2.insertTerm(-3, 1);
    p2.insertTerm(4, 0);

    cout << "P1 = "; p1.print();
    cout << "P2 = "; p2.print();

    Polynomial sum = p1.add(p2);
    cout << "P1 + P2 = "; sum.print();
}
