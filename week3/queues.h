#ifndef _QUEUES_H_
#define _QUEUES_H_

#include<queue>
#include "stacks.h"  // importing node definition

using namespace std;

queue<node> get_empty_node_queue();
void enqueue_node(queue<node> &q, node n);
node dequeue_node(queue<node> &q);

#endif