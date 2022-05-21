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
private:
   Graph network;

};

#endif