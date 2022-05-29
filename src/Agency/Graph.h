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

#include "minHeap.h"

using namespace std;

typedef pair<int, int> intPair;

struct Trip {
    int src;
    int dest;
    int capacity;
    int duration;

    bool operator == (const Trip &trip) const
    {
        return (src == trip.src && dest == trip.dest);
    }
};

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
    * @return A vector of integers that represent a path from src to dest.
    */
   vector<Trip> bfsPath(const int& src, const int& dest);

   /**
    * Uses the algorithm of Dijkstra to find the shortest path (less distance).
    * The algorithm of Dijkstra's time complexity is O(E log|V|).
    * @param src The starting node.
    * @param dest The destination node.
    * @return A vector of integers that represent a path from src to dest.
    */
   vector<Trip> dijkstraPath(const int& src, const int& dest);

   /**
    * Uses a variation of the algorithm of Dijkstra to find the path with maximum capacity.
    * The algorithm of Dijkstra's time complexity is O(E log|V|).
    * @param src The starting node.
    * @param dest The destination node.
    * @return A vector of integers that represent a path from src to dest.
    */
   vector<Trip> minmaxPath(const int& src, const int& dest);



    /**
     * Checks which path solution is better.
     * @param s11 first path solution.
     * @param s12 second path solution.
     * @return Returns '0' if pareto-optimal (non comparable). '1' if first solution is better, '2' if second solution is better.
     */
    int comparePaths(vector<Trip> s11, vector<Trip> s12);

private:

   /**
    * Makes a path vector from each node's predecessor. Time complexity is O(n).
    * @param src The starting node.
    * @param dest The destination node.
    * @return Returns a vector of the path taken from src to dest.
    */
   vector<Trip> getPath(const int& src, int dest);

   vector<int> getPathNodes(const int& src, int dest);
    int getPathCapacity(vector<Trip> path);

    int getPathTranshipments(vector<Trip> path);

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
   };

    vector<Node> nodes;

   int size;
};

#endif
