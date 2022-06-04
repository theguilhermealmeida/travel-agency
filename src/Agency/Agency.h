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
   Path scenario11(const int& src, const int& dest);

   /**
    * Scenario 1.2 - Maximize the group dimension and minimize number of transhipments.
    * @return //TODO
    */
   pair<Path, Path> scenario12(const int& src, const int& dest);

   /**
    * Scenario 2.1 - Get the path with maximum flow for a given group dimension.
    * The group splits up.
    * @param dimension Dimension needed for the group.
    * @param residual Matrix of adjacency's where the residual graph will be stored.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario21(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual);

   /**
    * Scenario 2.2 - Get the path with maximum flow for an increasing group dimension.
    * @param dimension Dimension needed for the group.
    * @param residual Matrix of adjacency's where the residual graph will be stored.
    * @param flow Current flow after the first allocation.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario22(const int& src, const int& dest, const int& dimension, vector<vector<int> >& residual, const int& flow);

   /**
    * Scenario 2.3 - Get the maximum path through the network when the group spits up.
    * @return Path with all the trips taken and respective flow.
    */
   Path scenario23(const int& src, const int& dest);

    Path scenario24(const int &src, const int &dest);
    Path scenario25(const int &src, const int &dest);

    int getGraphSize();

private:

   Graph network;
};

#endif