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
    * Print a summary of the Path.
    */
   void printInfo() const;

   /**
    * Print the full list of trips taken.
    */
   void printTrips() const;
private:
   int capacity;
   int duration;
   vector<Trip> trips;
};

#endif
