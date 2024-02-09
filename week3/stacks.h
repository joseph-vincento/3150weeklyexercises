#ifndef __STACKS_H
#define __STACKS_H

#include <stack>
#include <string>

using namespace std;

struct node {
  string name;
  int number;
};


stack<int> get_stack(const int n);
stack<node> get_stack_node(const int n);
stack<node> get_empty_node_stack();
void add_node_to_stack(stack<node> &s, node n);
node remove_top_node(stack<node> &s);

#endif