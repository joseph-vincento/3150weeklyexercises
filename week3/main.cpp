#include <iostream>
#include <fstream>
#include <string>
#include "stacks.h"
#include "queues.h"

void sum_of_stack(stack<node> &s, string fname);
void sum_of_queue(queue<node> &q, string fname);

int main() {
    using namespace std;

    stack<node> pos_stack = get_empty_node_stack();
    try {
        sum_of_stack(pos_stack, "pos_input.txt");
    } catch(string exc) {
        cout << "Something went wrong: " << exc << endl;
    }

    queue<node> pos_queue = get_empty_node_queue();
    try{
        sum_of_queue(pos_queue,"pos_input.txt");
    } catch(string exc) {
        cout << "Something went wrong: " << exc << endl;
    }

    stack<node> neg_stack = get_empty_node_stack();
    try {
        sum_of_stack(neg_stack, "neg_input.txt");
    } catch(string exc) {
        cout << "Something went wrong: " << exc << endl;
    }

    queue<node> neg_queue = get_empty_node_queue();
    try{
        sum_of_queue(neg_queue,"neg_input.txt");
    } catch(string exc) {
        cout << "Something went wrong: " << exc << endl;
    }

    return 0;
}

void sum_of_stack(stack<node> &s, string fname) {
    ifstream input_file;
    input_file.open(fname);
    
    while(!input_file.eof()) {
        string line;
        input_file >> line;

        node n;
        n.name = line;
        n.number = stoi(line);

        add_node_to_stack(s, n);
    }

    input_file.close();

    int sum = 0;
    while(!s.empty()) {
        node n;
        try {
            n = remove_top_node(s);
        } catch (string exc) {
            cout << "Something went wrong removing the top element: " << exc << endl;
            break;
        }
        sum += n.number;
    }
    
    if(sum < 0) {
        throw string("Stack sum is less than 0");
    } else {
        cout << "Stack sum is " << sum << endl;  
    }
}

void sum_of_queue(queue<node> &q, string fname) {
    ifstream input_file;
    input_file.open(fname);
    
    while(!input_file.eof()) {
        string line;
        input_file >> line;

        node n;
        n.name = line;
        n.number = stoi(line);

        enqueue_node(q, n);
    }

    input_file.close();

    int sum = 0;
    while(!q.empty()) {
        node n;
        try {
            n = dequeue_node(q);
        } catch (string exc) {
            cout << "Something went wrong removing the first element: " << exc << endl;
            break;
        }
        sum += n.number;
    }

    if(sum < 0) {
        throw string("Queue sum is less than 0");
    } else {
        cout << "Queue sum is " << sum << endl;  
    }
}