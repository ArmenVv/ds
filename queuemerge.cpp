#include <queue>
#include <stack>
using namespace std;

queue<int> mergeQueues(queue<int>& q1, queue<int>& q2) {
    queue<int> result;
    stack<int> temp;

    
    while (!q1.empty()) {
        result.push(q1.front());
        q1.pop();
    }

    
        temp.push(q2.front());
        q2.pop();
    }

    
    while (!temp.empty()) {
        result.push(temp.top());
        temp.pop();
    }

    return result;
}
