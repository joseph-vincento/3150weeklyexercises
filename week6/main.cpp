#include <iostream>
#include <vector>

#include "int_vector.h"

using namespace std;

int main() {

    vector<int_vector> vectors;
    vectors = read_int_vectors("vector_1.txt");

    if(!vectors.empty()) {
        vector<int_vector> new_vectors;
        new_vectors = copy_int_vectors(vectors);

        print_int_vectors_reverse(new_vectors);
    } else {
        cout << "The input file was empty!" << endl;
    }
    
    return 0;
}