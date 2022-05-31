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
    * @retun Path object with chosen path for this scenario.
    */
   Path scenario11(int src, int dest);

   /**
    * Scenario 1.2 - Maximize the group dimension and minimize number of transhipments.
    * @return //TODO
    */
   pair<Path, Path> scenario12();

   /**
    * Scenario 2.1 - Get the path with maximum flow for a given group dimension.
    * The group splits up.
    * @param dimension Dimension needed for the group.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario21(int src, int dest, const int& dimension);

   /**
    * Scenario 2.3 - Get the maximum path through the network when the group spits up.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario23(int src, int dest);

    /**
     * Getter for graph size.
     * @return Integer with graph size.
     */
    int getGraphSize();
private:

   Graph network;
};

#endif