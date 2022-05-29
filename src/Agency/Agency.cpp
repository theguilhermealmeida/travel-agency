#include "Agency.h"

Agency::Agency(const string &file_path) {
    network = Graph(file_path);
}

vector<Trip> Agency::scenario11() {
    return network.minmaxPath(1, 6);
}

vector<vector<Trip>> Agency::scenario12() {
    vector<vector<Trip>> result;
    vector<Trip> s11 = scenario11();
    vector<Trip> s12 = network.bfsPath(1, 6);

    int betterPath = network.comparePaths(s11, s12);

    if (betterPath == 0) {
        result.push_back(s11);
        result.push_back(s12);
        return result;
    }
    if (betterPath == 1) {
        result.push_back(s11);
        return result;
    }
    if (betterPath == 2) {
        result.push_back(s12);
        return result;
    }
}

