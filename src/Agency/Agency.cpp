#include "Agency.h"

Agency::Agency(const string &file_path) {
    network = Graph(file_path);
}

Path Agency::scenario11(const int& src, const int& dest) {
    return network.minmaxPath(src, dest);
}

pair<Path, Path> Agency::scenario12(const int& src, const int& dest) {
    return {network.bfsPath(src, dest), network.minmaxPath(src, dest)};
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

Path Agency::scenario24(const int& src, const int& dest) {
    Path s23 = scenario23(src, dest);
    return network.minDuration(s23, src, dest);
}

int Agency::getGraphSize() {
   return network.getSize();
}