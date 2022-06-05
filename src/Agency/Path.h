#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Represents a trip taken from one stop to another.
 */
struct Trip {
    /** Trip's origin point. */
    int src;
    /** Trip's destination point. */
    int dest;
    /** The capacity supported by the trip. */
    int capacity;
    /** Flow going through this trip. */
    int flow;
    /** Duration of the trip. */
    int duration;

    bool operator == (const Trip &trip) const
    {
        return (src == trip.src && dest == trip.dest);
    }
};

class Path {
public:
   /**
    * Path's default constructor.
    */
   Path();

   /**
    * Get the vector of trips used by this path.
    * @return Vector o Trip object.
    */
   vector<Trip> getTrips() const;

   /**
    * Add a trip to the path.
    * @param trip Trip struct to be added.
    */
   void addTrip(const Trip& trip);

   /**
    * Set the flow of the path. Best suited when the group splits up.
    * @param flow Maximum flow through the path.
    */
   void setFlow(const int& flux);

   /**
    * Get the maximum flow through the path.
    * @return Integer with maximum flow.
    */
   int getFlow() const;

   /**
    * Print a summary of the Path.
    */
   void printInfo() const;

   /**
    * Print the full list of trips taken.
    */
   void printTrips() const;


   /**
    * Adds node with maximum waiting time to vector of waiting time nodes.
    * @param node Node to add to vector.
    */
    void add_waiting_time_node(int node);

    /**
     * Getter for waiting time nodes vector.
     * @return Vector with nodes with maximum waiting time.
     */
    vector<int> get_waiting_time_nodes();

    /**
     * Getter for maximum waiting time.
     * @return Maximum waiting time in path.
     */
   int getWaitingTime();

   /**
    * Getter for minimal duration of project (path).
    * @return Minimal duration of a project (path).
    */
   int getMinTime();

   /**
    * Setter for maximum waiting time.
    * @param waiting_time New maximum waiting time of a path.
    */
    void setWaitingTime(int waiting_time);

    /**
     * Setter for minimal duration of a project (path).
     * @param min_time New minimal duration of project (path).
     */
    void setMinTime(int min_time);
private:
    int capacity;
    int flow;
    int duration;
    int waiting_time;
    int min_time;

    vector<Trip> trips;

    vector<int> waiting_time_nodes;
};

#endif
