#ifndef AGENCY_H
#define AGENCY_H

#include <string>

#include "Graph.h"

class Agency {

public:
   Agency() = default;

   Agency(const string& file_path);
private:
   Graph network;

};

#endif