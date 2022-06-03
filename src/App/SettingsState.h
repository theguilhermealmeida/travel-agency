#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include <iostream>

#include "State.h"
#include "InitialState.h"

class SettingsState : public State {
   void step(App* app) override;

   /**
    * Change the input file of the program.
    * @param app Pointer to main application.
    */
   void changeFile(App* app);

   /**
    * Display a list of text files.
    * @param app Pointer to main application.
    */
   void displayFiles(App* app) const;
};

#endif
