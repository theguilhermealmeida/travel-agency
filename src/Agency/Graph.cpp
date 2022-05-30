#include "Graph.h"

Graph::Graph(const int& size) : nodes(size + 1) {
    this->size = size;
}

Graph::Graph(const string &file_path) {
    int src, dest, capacity, duration, line = 1;
    string row, word;
    stringstream str;
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Unable to open file " << file_path << endl;
        return;
    }

    try {
        getline(file, row);
        str = stringstream(row);
        getline(str, word, ' ');
        this->size = stoi(word);
        nodes.resize(size + 1);

        while (getline(file, row)) {
            line++;
            str = stringstream(row);
            getline(str, word, ' ');
            src = stoi(word);
            getline(str, word, ' ');
            dest = stoi(word);
            getline(str, word, ' ');
            capacity = stoi(word);
            getline(str, word, ' ');
            duration = stoi(word);
            addEdge(src, dest, capacity, duration);
        }
    } catch (invalid_argument) {
        cout << "Error in the test file. Line " << line << ".\n";
    }
}

void Graph::addEdge(const int& src, const int& dest, const int& capacity, const int& duration)
{
    if (src < 1 || src > size || dest < 1 || dest > size) return;
    nodes[src].adj.push_back({dest, capacity, duration});
}

bool Graph::connected(const int &src, const int &dest)
{
    for (auto e: nodes[src].adj)
    {
        if (e.dest == dest) return true;
    }
    return false;
}

vector<int> Graph::bfsPath(const int& src, const int& dest)
{
    for (int v=1; v <= size; v++) {
        nodes[v].visited = false;
        nodes[v].predecessor = 0;
    }
    queue<int> q;
    q.push(src);
    nodes[src].visited = true;
    nodes[src].distance = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj)
        {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                nodes[w].predecessor = u;
            }
        }
    }
    return getPath(src, dest);
}

vector<int> Graph::bfsResidualPath(const int& src, const int& dest)
{
    for (int v=1; v <= size; v++) {
        nodes[v].visited = false;
        nodes[v].predecessor = 0;
    }
    queue<int> q;
    q.push(src);
    nodes[src].visited = true;
    nodes[src].distance = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto e : nodes[u].residual_adj)
        {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                nodes[w].predecessor = u;
            }
        }
    }
    return getPath(src, dest);
}

vector<int> Graph::dijkstraPath(const int &src, const int &dest) {
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = 0;
    }
    nodes[src].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(src, nodes[src].distance);
    while(h.getSize()>0){
        int x = h.removeMin();
        nodes[x].visited = true;
        for (Edge e: nodes[x].adj){
            if (!nodes[e.dest].visited
                && nodes[e.dest].distance > nodes[x].distance + e.duration) {
                    nodes[e.dest].distance = nodes[x].distance + e.duration;
                    nodes[e.dest].predecessor = x;
                    if (!h.hasKey(e.dest)) {
                        h.insert(e.dest, nodes[e.dest].distance);
                    } else {
                        h.decreaseKey(e.dest, nodes[e.dest].distance);
                    }
            }
        }
    }
    return getPath(src, dest);
}

vector<int> Graph::minmaxPath(const int &src, const int &dest) {
    for (int i=1;i<=size;i++){
        nodes[i].distance = -1;
        nodes[i].visited = false;
        nodes[i].predecessor = 0;
    }
    nodes[src].distance = INT_MAX;
    priority_queue<intPair, vector<intPair>, less<intPair>> h;
    h.push({nodes[src].distance, src});
    while(h.size() > 0){
        int u = h.top().second;
        h.pop();
        nodes[u].visited = true;
        for (Edge e: nodes[u].adj){
            int min_dist = min(nodes[u].distance, e.capacity);
            if (!nodes[e.dest].visited && min_dist > nodes[e.dest].distance) {
                nodes[e.dest].distance = min_dist;
                nodes[e.dest].predecessor = u;
                h.push({nodes[e.dest].distance, e.dest});
            }
        }
    }
    return getPath(src, dest);
}

int Graph::maxFlow(const int &src, const int &dest) {
    int max_flow = 0;
    vector<int> path;
    for (int i = 1; i<= size; i++) {
        nodes[i].residual_adj.clear();
        nodes[i].residual_adj = nodes[i].adj;
    }
    while (!(path = bfsResidualPath(src, dest)).empty()) {
        int path_flow = 0;
        for (int n : path) {
            //path_flow += min(nodes[n].ca)
            //TODO é melhor ter struct do caminho para poder sacar as edges
        }
    }
    return max_flow;
}

vector<int> Graph::getPath(const int& src, int dest)
{
    if (nodes[dest].predecessor == 0) return {};
    vector<int> path;
    do {
        path.push_back(dest);
        dest = nodes[dest].predecessor;
    } while (dest != 0);
    reverse(path.begin(), path.end());
    return path;
}
