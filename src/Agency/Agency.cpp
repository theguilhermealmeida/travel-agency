#include "Agency.h"

Agency::Agency(const string &file_path) {
    network = Graph(file_path);
}

vector<int> Agency::scenario11() {
    return network.minmaxPath(1, 6);
}