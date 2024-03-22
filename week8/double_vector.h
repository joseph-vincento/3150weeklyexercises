#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <utility>


using namespace std;

struct double_vector {
    double x;
    double y;
    
    double_vector(const double_vector & dv) : x(dv.x), y(dv.y) {};
    
    double_vector() : x(0.0), y(0.0) {};
    double_vector(double x, double y) :  x(x), y(y) {};
};

/**/
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);
vector<double_vector> read_vectors(ifstream & in_stream);
vector<pair<double, pair<double_vector, double_vector>>> calc_pairwise_cosine_distances(const vector<double_vector> & vectors);
bool cosine_distance_comparison(
    const pair<double, pair<double_vector, double_vector>> & dv_pair1,
    const pair<double, pair<double_vector, double_vector>> & dv_pair2
);

#endif