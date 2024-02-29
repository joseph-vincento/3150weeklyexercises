#include <istream>
#include <fstream>
#include <iostream>

#include "int_vector.h"

using namespace std;

vector<int_vector> read_int_vectors(const string &file_name) {
    vector<int_vector> vectors;

    ifstream in_file;
    in_file.open(file_name);

    int id = 0;
    int from, to;
    while(in_file >> from >> to) {
        int_vector iv;
        iv.id = id;
        iv.from = from;
        iv.to = to;
        vectors.push_back(iv);
        id++;
    }

    in_file.close();
    return vectors;
}

vector<int_vector> copy_int_vectors(const vector<int_vector> &org_vectors) {
    vector<int_vector> new_vectors;
    for(int_vector iv : org_vectors) {
        int_vector new_vector(iv);
        new_vectors.push_back(new_vector);
    }

    return new_vectors;
}

void print_int_vectors_reverse(const vector<int_vector> &vectors) {
    for(auto iv = vectors.rbegin(); iv != vectors.rend(); iv++) {
        cout << iv->id << ": " << iv->from << " " << iv->to << endl;
    }
}
