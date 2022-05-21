#include "Graph.h"

Graph::Graph(const int& size) : nodes(size + 1) {
    this->size = size;
}

Graph::Graph(const string &file_path) {
    int src, dest, capacity, duration;
    string row, word;
    stringstream str;
    ifstream file(file_path);
    if (!file.is_open()) return;

    str = stringstream(row);
    getline(str, word, ' ');
    this->size = stoi(word);
    nodes.resize(size + 1);

    while (getline(file, row))
    {
        str = stringstream (row);
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
