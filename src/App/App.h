#ifndef APP_H
#define APP_H

#include <set>

#include "../src/Agency/Agency.h"
#include "State.h"

class State;

struct appSettings {
    string file_path; /** Location of the test file. */
};

class App
{
public:
   /**
    * App's default constructor. Starts everything needed for the program.
    */
   App();

   /**The application main loop.**/
   void run();

   /**
    * Get the app's Agency object.
    * @return Pointer to the app's Agency.
    */
   Agency* getAgency() const;

   /**
    * Get the app current settings.
    * @return Struct appSettings with all current settings.
    */
   struct appSettings getSettings() const;

   /**
    * Change the app's current state.
    * @param state Any state derived class.
    */
   void setState(State* state);

private:
    Agency* agency;
    State* state;

   struct appSettings settings;
};


#endif