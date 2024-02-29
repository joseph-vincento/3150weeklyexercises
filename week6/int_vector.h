#include <vector>
#include <istream>

using namespace std;

struct int_vector {
    int id;
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
    int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};

vector<int_vector> read_int_vectors(const string &file_name);
vector<int_vector> copy_int_vectors(const vector<int_vector> &org_vectors);
void print_int_vectors_reverse(const vector<int_vector> &vectors);
