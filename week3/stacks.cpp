#include <iostream>
#include <stack>
#include <string>

#include "stacks.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

stack<node> get_stack_node(const int n) {
  stack<node> s;

  for (int i=0; i < n; i++) {
    if (i >= sizeof(names)) {
      node my_node;
      my_node.name = "Plato";
      my_node.number = i;
      
      s.push(my_node);
    } else {
      node my_node;
      my_node.name = names[i];
      my_node.number = i;
      
      s.push(my_node);
    }
  }

  return s;
}

stack<node> get_empty_node_stack() {
    stack<node> s;
    return s;
}

void add_node_to_stack(stack<node> &s, node n) {
    s.push(n);
}

node remove_top_node(stack<node> &s) {
    if(!s.empty()) {
        node n = s.top();
        s.pop();
        return n;
    } else {
        throw string("Stack is already empty");
    }
}

stack<int> get_stack(const int n) {

  stack<int> s;

  for (int i=0; i < n; i++) {
    s.push(i);
  }

  return s;
}

// stack<int> get_stack() {
//     // returns an empty stack of ints

//     stack<int> new_stack;
//     return new_stack;
// }

// void add_to_stack(stack<int> &s, int n) {
//     s.push(n);
// }

// int remove_top(stack<int> &s) {
//     if(!s.empty()) {
//         int n = s.top();
//         s.pop();
//         return n;
//     } else {
//         return 0;
//     }
// }