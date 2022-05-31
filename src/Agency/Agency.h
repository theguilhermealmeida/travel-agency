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
   Path scenario11();

   /**
    * Scenario 1.2 - Maximize the group dimension and minimize number of transhipments.
    * @return //TODO
    */
   pair<Path, Path> scenario12();

   //TODO find a way to display the path
   int scenario21(const int& dimension);
   int scenario23();

private:
   Graph network;
};

#endif