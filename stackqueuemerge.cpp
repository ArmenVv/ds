#include <queue>
#include <stack>
using namespace std;

queue<int> mergeQueueStack(queue<int>& q, stack<int>& s) {
    queue<int> result;


    while (!q.empty()) {
        result.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        result.push(s.top());
        s.pop();
    }

    return result;
}
