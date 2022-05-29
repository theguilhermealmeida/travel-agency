#ifndef AGENCY_H
#define AGENCY_H

#include <string>

#include "Graph.h"

class Agency {

public:
   Agency() = default;

   /**
    * Create an agency object from a text file.
    * @param file_path The path to a proper file with the network information.
    */
   Agency(const string& file_path);

   /**
    * Scenario 1.1 - Maximize the group dimension when the group stays together.
    * @return Vector of the taken path (integers).
    */
   vector<Trip> scenario11();

   /**
    * Scenario 1.2 - Maximize the group dimension and minimize number of transhipments.
    * @return 2D vector with pareto-optimal solutions.
    */
   vector<vector<Trip>> scenario12();

private:

   Graph network;
};

#endif