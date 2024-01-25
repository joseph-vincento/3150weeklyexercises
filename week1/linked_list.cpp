#include <iostream>

#include "linked_list.h"


using namespace std;


Node* build_new_linked_list(int list_size) {
    /*
    build_new_linked_list:
    returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return nullptr
    */
    if (0 >= list_size) {
        return nullptr;
    } else {
        Node* root = nullptr;
        Node* current_node = nullptr;

        for(int i = 0; i < list_size; i++) {
            Node* new_node = new Node;
            new_node->data = i + 1;
            new_node->next = nullptr;
            if(!root) {
                root = new_node;
                current_node = new_node;
            }
            else {
                current_node->next = new_node;
                current_node = new_node;
            }
        }

        return root;
    }
}

int get_linked_list_data_item_value(Node* root, int node_number, int list_size) {
    /*
    get_linked_list_data_item_value:
    returns -1 if not enough nodes
    */
    // Bradford code
    // if (node_number > list_size) {
    //     return -1;
    // } else {
    //     Node* linked_list = start;

    //     for (int i = 0; i < node_number -1; i++) {
    //         linked_list = linked_list->next;
    //     }

    //     return linked_list->data;
    // }

    if(node_number > list_size) {
        return -1;
    }

    for(int i = 0; i < node_number - 1; i++) {
        root = root->next;
    }

    return root->data;
}

void print_linked_list(Node* root) {
    // Bradford code
    // Node* linked_list = start;

    // for (int i = 0; i < list_size; i++) {
    //     cout << linked_list->data << endl;
    //     linked_list = linked_list->next;
    // }

    while(root) {
        cout << root->data << endl;
        root = root->next;
    }
}


bool update_data_in_linked_list(Node* root, int node_to_update, int update_val, int list_size) {
    /*
    update_data_in_linked_list:
    Returns false if node_to_update > list_size
    Returns true otherwise
    */
    if(node_to_update > list_size) {
        return false;
    }
    else {
        for(int i = 0; i < node_to_update - 1; i++) {
            root = root->next;
        }
        root->data = update_val;
        return true;
    }
}

void delete_linked_list(Node* root) {
    if(root == nullptr) {
        return;
    }
    delete_linked_list(root->next);
    delete root;
    root = nullptr; // explicitly set pointer to null after delete
}