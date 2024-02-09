#include <string>
#include "queues.h"

using namespace std;

queue<node> get_empty_node_queue() {
    queue<node> q;
    return q;
}

void enqueue_node(queue<node> &q, node n) {
    q.push(n);
}

node dequeue_node(queue<node> &q) {
    if(!q.empty()) {
        node n = q.front();
        q.pop();
        return n;
    } else {
        throw string("The queue is already empty");
    }
}