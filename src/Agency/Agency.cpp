#include "Agency.h"

Agency::Agency(const string &file_path) {
    network = Graph(file_path);
}

Path Agency::scenario11(const int& src, const int& dest) {
    return network.minmaxPath(src, dest);
}

pair<Path, Path> Agency::scenario12() {
    //TODO decide which one to display here
    return {network.bfsPath(1, 6), network.minmaxPath(1, 6)};
    /*
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
     */
}

Path Agency::scenario21(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual) {
    return network.maxFlow(src, dest, residual, dimension);
}

Path Agency::scenario22(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual, const int& flow) {
    return network.maxFlowFromPath(src, dest, residual, flow, dimension);
}

Path Agency::scenario23(const int& src, const int& dest) {
    return network.maxFlow(src, dest);
}


int Agency::getGraphSize() {
   return network.getSize();
}