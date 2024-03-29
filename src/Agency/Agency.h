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
    * @param src Source node.
    * @param dest Destination node.
    * @retun Path object with chosen path for this scenario.
    */
   Path scenario11(const int& src, const int& dest);

   /**
    * Scenario 1.2 - Maximize the group dimension and minimize number of transhipments.
    * @param src Source node.
    * @param dest Destination node.
    * @return Both the path that maximizes group dimension and the path that minimizes transhipments.
    */
   pair<Path, Path> scenario12(const int& src, const int& dest);

   /**
    * Scenario 2.1 - Get the path with maximum flow for a given group dimension.
    * The group splits up.
    * @param src Source node.
    * @param dest Destination node.
    * @param dimension Dimension needed for the group.
    * @param residual Matrix of adjacency's where the residual graph will be stored.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario21(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual);

   /**
    * Scenario 2.2 - Get the path with maximum flow for an increasing group dimension.
    * @param src Source node.
    * @param dest Destination node.
    * @param dimension Dimension needed for the group.
    * @param residual Matrix of adjacency's where the residual graph will be stored.
    * @param flow Current flow after the first allocation.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario22(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual, const int& flow);

   /**
    * Scenario 2.3 - Get the maximum path through the network when the group spits up.
    * @param src Source node.
    * @param dest  Destination node.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario23(const int& src, const int& dest);

   /**
    * Scenario 2.4 - Find the minimum time for the group to reunite at the destination.
    * @param src Source node.
    * @param dest Destination node.
    * @return
    */
    Path scenario24(const int &src, const int &dest);

    /**
     * Scenario 2.5 - Find where there's the longest waiting time and the respective time.
     * @param src Source node.
     * @param dest Destination node.
     * @return
     */
    Path scenario25(const int &src, const int &dest);

    int getGraphSize();

private:

   Graph network;
};

#endif