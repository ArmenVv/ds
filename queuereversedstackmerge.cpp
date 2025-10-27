#include <queue>
#include <stack>
using namespace std;

queue<int> mergeQueueReversedStack(queue<int>& q, stack<int>& s) {
    queue<int> result;
    stack<int> temp;

   
    while (!q.empty()) {
        result.push(q.front());
        q.pop();
    }

   
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    
    while (!temp.empty()) {
        result.push(temp.top());
        temp.pop();
    }

    return result;
}
