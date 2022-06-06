#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include <iostream>

#include "State.h"
#include "SettingsState.h"
#include "ChooseSceneryState.h"

class InitialState : public State {
    /**
    * Handle the specific in the initial state.
    * @param app Pointer to the main application.
    */
   void step(App* app) override;
};

#endif
