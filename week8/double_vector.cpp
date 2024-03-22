
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "double_vector.h"


using namespace std;


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    return one.x* two.x + one.y* two.y;
}

double magnitude(const double_vector & my_vector) {
    return sqrt(square(my_vector.x) + square(my_vector.y));
};


double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude) ;

    return acos(d);
}

vector<double_vector> read_vectors(ifstream &in_stream) {
    double x, y;
    vector<double_vector> rv;
    while(in_stream >> x >> y) {
        rv.push_back(double_vector(x, y));
    }

    return rv;
}

vector<pair<double, pair<double_vector, double_vector>>> calc_pairwise_cosine_distances(const vector<double_vector> & vectors) {
    // https://en.cppreference.com/w/cpp/utility/pair
    // create a vector of pairs
    // each pair contains a double and an inner pair
    // each inner pair contains two double_vectors
    // i.e.: cosine_distances[0] == {1.0, {dv1, dv2}}
    vector<pair<double, pair<double_vector, double_vector>>> cosine_distances;

    int n = vectors.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double pairwise_distance = cosine_distance(vectors[i], vectors[j]);
            cosine_distances.push_back({pairwise_distance, {vectors[i], vectors[j]}});
        }
    }

    return cosine_distances;
}

bool cosine_distance_comparison(
    const pair<double, pair<double_vector, double_vector>>  & dv_pair1,
    const pair<double, pair<double_vector, double_vector>>  & dv_pair2
) {
    // Compare calculated cosine distances as per documentation
    // on parameter specification for sort()
    // https://en.cppreference.com/w/cpp/algorithm/sort
    return dv_pair1.first < dv_pair2.first;
}