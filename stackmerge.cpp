#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1, s2, temp;

    
    s1.push(1); s1.push(2); s1.push(3); 
    s2.push(4); s2.push(5); s2.push(6); 

   
    while (!s2.empty()) {
        temp.push(s2.top());
        s2.pop();
    }

   
    while (!temp.empty()) {
        s1.push(temp.top());
        temp.pop();
    }

    
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n"; 
}
