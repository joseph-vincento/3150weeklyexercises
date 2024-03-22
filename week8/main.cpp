#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include "double_vector.h"

using namespace std;

int main() {
    ifstream in_file("vectors.txt");
    vector<double_vector> vectors = read_vectors(in_file);
    in_file.close();

    vector<pair<double, pair<double_vector, double_vector>>> distances = 
        calc_pairwise_cosine_distances(vectors);

    sort(distances.begin(), distances.end(), cosine_distance_comparison);

    for(auto const &pair : distances) {
        cout << "Cosine distance: " << pair.first << " ";
        cout << "Vectors: (" << pair.second.first.x << ", " << pair.second.first.y
            << "), (" << pair.second.second.x << ", " << pair.second.second.y << ")" << endl;
    }
    return 0;
}