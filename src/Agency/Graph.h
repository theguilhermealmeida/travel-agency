#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>

#include "minHeap.h"
#include "Path.h"

using namespace std;

typedef pair<int, int> intPair;

class Graph {

public:
   /**
    * Default constructor for graph.
    */
   Graph() = default;

   /**
    * Constructs a graph with specific size.
    * @param size The number of nodes.
    */
   Graph(const int& size);

   /**
    * Constructs a graph from a txt file.
    * @param file_path Path to an appropriate file to be loaded.
    */
   Graph(const string& file_path);

   /**
    * Add an edge to the graph in O(1) time complexity.
    * @param src The origin node.
    * @param dest The destination node.
    * @param capacity Vehicle's capacity.
    * @param duration The trip's duration.
    */
   void addEdge(const int& src, const int& dest, const int& capacity, const int& duration);

   /**
    * Determine if a node connects to another node.
    * @param src The origin node.
    * @param dest The destination node.
    * @return Returns true if node src connects to node dest and false otherwise.
    */
   bool connected(const int& src, const int& dest);

   /**
    * Uses breadth-first search to find the shortest path (less nodes).
    * The bfs' time complexity is O(V + E) and after that its O(n) to get the path.
    * @param src The starting node.
    * @param dest The destination node.
    * @return A Path object with the path taken by BFS.
    */
   Path bfsPath(const int& src, const int& dest);

   /**
    * Uses the algorithm of Dijkstra to find the fastest path (less duration).
    * The algorithm of Dijkstra's time complexity is O(E log|V|).
    * @param src The starting node.
    * @param dest The destination node.
    * @return A Path object with the path from src to dest.
    */
   Path dijkstraPath(const int& src, const int& dest);

   /**
    * Uses a variation of the algorithm of Dijkstra to find the path with maximum capacity.
    * The algorithm of Dijkstra's time complexity is O(E log|V|).
    * @param src The starting node.
    * @param dest The destination node.
    * @return A Path object that represent a path from src to dest.
    */
   Path minmaxPath(const int& src, const int& dest);

   /**
    * Get the maximum flow for the graph using the Ford-Fulkerson method.
    * //TODO add time complexity
    * @param src The starting node.
    * @param dest The destination node.
    * @param dimension Optional: The group's dimension. This acts as a delimiter.
    * @return Path with all the trips taken and respective flow.
    */
   Path maxFlow(const int& src, const int& dest, int dimension = INT_MAX);

   /**
    * Get the maximum flow for the graph using the Ford-Fulkerson method.
    * This method stores the residual graph in an adjacency matrix;
    * //TODO add time complexity
    * @param src The starting node.
    * @param dest The destination node.
    * @param residual Matrix of adjacency's where the residual graph will be stored.
    * @param dimension Optional: The group's dimension. This acts as a delimiter.
    * @return Path with all the trips taken and respective flow.
    */
   Path maxFlow(const int& src, const int& dest, vector<vector<int> >& residual, int dimension = INT_MAX);

   /**
    * Get the maximum flow for the graph using the Ford-Fulkerson method and starting with an
    * already filled residual graph.
    * //TODO add time complexity
    * @param src The starting node.
    * @param dest The destination node.
    * @param residual Already filled adjacency matrix. The flow will be calculated from this data.
    * @param flow Current flow considering already filled path.
    * @param dimension Optional: The group's dimension. This acts as a delimiter.
    * @return Path with all the trips taken and respective flow.
    */
   Path maxFlowFromPath(const int& src, const int& dest, vector<vector<int> >& residual, int flow, int dimension = INT_MAX);

   /**
    * Get the minimal duration of a path.
    * @param path Path to calculate minimal duration.
    * @param src Source node.
    * @param dest Destination node.
    * @return
    */
    Path minDuration(Path path, const int& src, const int& dest);

    /**
     * Get the maximum waiting time in the path and the respective nodes.
     * @param path Path to calculate maximum waiting time.
     * @param src Source node.
     * @param dest Destination node.
     * @return
     */
    Path maxDuration(Path path, const int &src, const int &dest);

    /**
     * Getter for size of graph.
     * @return Size of graph.
     */
    int getSize();

private:

   /**
    * Uses breadth-first search to find the shortest path (less nodes) in the residual graph.
    * The bfs' time complexity is O(V + E) and after that its O(n) to get the path.
    * This method computes the bfs from an adjacency matrix, previously created.
    * @param src The starting node.
    * @param dest The destination node.
    * @return A vector of nodes taken from src to dest.
    */
   vector<int> bfsAdjacencyPath(const int& src, const int& dest, vector<vector<int> > graph);
    /**
    * Makes a path vector from each node's predecessor. Time complexity is O(n).
    * @param src The starting node.
    * @param dest The destination node.
    * @return Returns a vector of the path taken from src to dest.
    */
   Path getPath(const int& src, int dest);

    /**
    * Create a path from a residual network.
    * @param residual Adjacency matrix representing the residual graph.
    * @param flow Maximum flow achieved through the path.
    * @return Path with all the trips taken and respective flow.
    */
   Path getPathFromResidual(const vector<vector<int> >& residual, const int& flow);

   /**
    * Get the nodes that belong to a path.
    * @param src Source node.
    * @param dest Destination Node.
    * @return Vector with path nodes.
    */
    vector<int> getPathNodes(const int& src, int dest);

    struct Edge {
       int dest;
       int capacity;
       int duration;
   };

    struct Node {
       list<Edge> adj;
       bool visited;
        int distance;
        int predecessor;
        int degree;
        int slowest_time;
        int fastest_time;
        int waiting_time;
    };

    vector<Node> nodes;

   int size;
};

#endif
